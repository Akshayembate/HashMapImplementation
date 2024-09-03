#include <iostream>
#include <sstream>

class HashTable
{
public:
    // public variables 
    //size of the table
    static const int Size = 26;

    struct Entry
    {
        std::string Data;
        std::string Status = "never used";
    };
public:
    HashTable() = default;

    // function for printing the status of the hash tabels 
    void print()
    {
        for (int i = 0; i < Size; i++)
        {
            std::cout << m_Entries[i].Data << "(" << "status :" << m_Entries[i].Status  << ")\n";
        }
    }

    void Add(const std::string& entryString)
    {
        // find the entrystring is exists
        bool exists = Find(entryString);
        if (exists)
            return;
        
        // insert index , if exists it will check to the next index
        int insertIndex = GetInsertIndex(entryString);

        // adding the data
        m_Entries[insertIndex].Data = entryString;
        m_Entries[insertIndex].Status = "occupied";
        
    }

    void Delete(const std::string& entryString)
    {
        // find the index which is exist
        bool exists = Find(entryString);
        if (!exists)
            return;

        int index = GetDeleteIndex(entryString); 
        //m_Entries[index].Data.clear();
        m_Entries[index].Status = "tombstone";           
    }

    //~HashTable();
private:
    int GetIndex(const std::string& entryString)
    {
        // get the index of the last value in the string 
        // example if apple is the entryString then the last charector is e and we need to return the index of e in the alphebet hashtabel 
        return (entryString.back() -'a'); // the enttrystring.back will return a value which is the last charector substrating with a will give the index in the alphebetic order 
    }  

    bool Find(const std::string entryString)
    {
        // find the index of the token from the getindex function
        int index = GetIndex(entryString);
        //int startIdx = index;

        while (true)
        {
            // check the entry string is exist in the existing hash table
            if (m_Entries[index].Data == entryString)
                //if (outIndex){
                //   *outIndex = index;}
                return true;

            // check the index is not used 
            if (m_Entries[index].Status == "never used")
                return false;
            // increment the index
            index = (index + 1) % Size;

            //if (index == startIdx)
            //    return false;
        }
        return false;
    }

    int GetInsertIndex(const std::string& entryString)
    {
        // index of the string from the entry string
        int index = GetIndex(entryString);
        while (true)
        {
            // chekc the status of the hash map is occupied
            if (m_Entries[index].Status == "never used" || m_Entries[index].Status == "tombstone")
                return index;
                
            index = (index + 1) % Size;
        }
        return -1;
    }

    int GetDeleteIndex(const std::string& entryString)
    {
        int index = GetIndex(entryString);
        while (true)
        {
            if (m_Entries[index].Data == entryString)
            {
                return index;
            } 
            index = (index + 1) % Size;  
        }
        
    }
private:
    // private variables 
    Entry m_Entries[Size];
};

int main()
{
    // Aapple Aorange Dapple Astrawberry
    // orange strawberry
    // std::cout << "hellow world\n";

    // seperate token from the command line argument 
    // declare the variable coming in the commadn line input 
    std::string input;

    // read the text in the commnad line and stores inside the cariable input
    getline(std::cin, input);

    HashTable hashTable;

    //treat the string like a stream 
    std::stringstream ss(input);

    while (ss.good())
    {
        std::string token;
        // read the words from strem and store in ss until the ss.good fails
        ss >> token;

        //std::cout << token << "\n";
        std::string entryString = &token[1];
        if (token[0] == 'A')
        {
            //std::cout << "add -" << entryName << "\n";
            hashTable.Add(entryString);
        }
        else if (token[0] == 'D')
        {
            //std::cout << "delete - " <<entryName << "\n";
            hashTable.Delete(entryString);
        }
    }
    hashTable.print();
    std::cin.get();
}