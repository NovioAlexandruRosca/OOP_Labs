#pragma once
#include <iostream>
#include <tuple>

using namespace std;

// for each  // auto //

template <typename T1, typename T2>
class Map
{

private:
    class KeyValue
    {
    public:
        T1 key;
        T2 value;
        int index = 0;
    };
    KeyValue *map;
    int number_of_keys;

public:

    Map()
    {
        number_of_keys = 0;
        map = new KeyValue[1];

    }
    ~Map()
    {
        delete[] map;
    }

    KeyValue* begin() const
    {
        return &map[0];
    }

    KeyValue* end() const
    {
        return &map[number_of_keys];
    }

    T2& operator[] (T1 key_value)
    {

        for (int i = 0 ; i < number_of_keys ; i++)
        {
            if (map[i].key == key_value)
                return map[i].value;
        }

        KeyValue* copie = new KeyValue[number_of_keys + 1];

        for (int i = 0; i < number_of_keys; i++)
            copie[i] = map[i];

        delete[] map;
        map = copie;

        number_of_keys++;       
        if(number_of_keys >= 2)
            map[number_of_keys - 1].index = map[number_of_keys - 2].index + 1;
        map[number_of_keys - 1].key = key_value;
        return map[number_of_keys - 1].value;
    }
       
    void Set(T1 key, T2 value)
    {
        (*this)[key] = value;
    }

    int Count()
    {
        return number_of_keys;
    }

    void Clear()
    {
        delete[] map;

        number_of_keys = 0;
        map = new KeyValue[1];
    }

    void Delete(T1 key)
    {

        for (int i = 0; i < number_of_keys; i++)
        {
            if (map[i].key == key)
            {

                for (int j = i; j < number_of_keys - 1; j++)
                {
                    map[j] = map[j + 1];
                    map[j].index--;
                }

                KeyValue* copie = new KeyValue[number_of_keys];

                for (int i = 0; i < number_of_keys - 1; i++)
                    copie[i] = map[i];

                delete[] map;
                map = copie;

                number_of_keys--;

                break;
            }
        }
    }

    bool Get(const T1& key, T2& value)
    {
        int OK = 0;
        for (int i = 0; i < number_of_keys; i++)
        {
            if (key == map[i].key)
            {
                OK = 1;
                value = map[i].value;
                break;
            }
        }
        return OK;
    }

    bool Includes(const Map<T1, T2>& map1)
    {
        int OK = 1;
        for (auto j : map1)
        {
            int exists = 0;
            
            for (int i = 0; i < number_of_keys; i++)
                if (map[i].key == j.key)
                    exists = 1;
            
            if (!exists)
                OK = 0;
        }

        return OK;
    }
};