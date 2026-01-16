#ifndef MYDSLIB_H
#define MYDSLIB_H
// CODE 1: Include necessary library(ies)
#include <stddef.h>
#include <stdbool.h>


#define MAX_FIELD_LEN 100           // DO NOT CHANGE: for more info check Record struct (we know it is always less than 100 chars)
#define MAX_TRANSACTION_ID_LEN 39   // DO NOT CHANGE: for more info check Record struct (we know this column is always 38 character plus one null terminator)
#define MAX_POSTCODE_LEN 9          // DO NOT CHANGE: for more info check Record struct (we know that this column has max 8+1 chars)


#define INDEX_SIZE 180001  // CODE 2: you must find a proper value that balances size/performance
/*
I experimented and tried to pick a prime number that would give me a load factor of around 0.7. (Prime nums I believe work better for modulo)
*/

// CODE 3: You can add more constants with #define here if needed

// DO NOT CHANGE: Date
typedef struct {
    int year, month, day;
} Date;

// DO NOT CHANGE: Record
typedef struct {
    char transaction_id[MAX_TRANSACTION_ID_LEN];
    unsigned int price;
    Date date;
    char postcode[MAX_POSTCODE_LEN];
    char property_type;      // One character
    char old_new;            // One character
    char duration;           // One character
    char paon[MAX_FIELD_LEN];
    char saon[MAX_FIELD_LEN];
    char street[MAX_FIELD_LEN];            
    char locality[MAX_FIELD_LEN];
    char town[MAX_FIELD_LEN];
    char *district;          // Allocated dynamically
    char county[MAX_FIELD_LEN];
    char record_status;      // One character
    char blank_col;          // One character
} Record;

// DO NOT CHANGE: IndexEntry
typedef struct IndexEntry {
    char* key;           // The street name (copied from table[i].street)
    Record* record_ptr;  // Pointer back to original record
    struct IndexEntry* next;
} IndexEntry;


// Global table pointer
extern Record* table;    // DO NOT CHANGE: A global pointer to save the read data from csv files (a pointer to array of Records)
extern size_t table_size;// DO NOT CHANGE: A global variable showing the number of rows (number of Records) read from csv files (rows in table)
// CODE 4: ADD more global variables if you need

// CODE 5: Declare necessary functions here (only the functions being used files other than myDSlib.c)
void read_file(char* file_name);
IndexEntry** createIndexOnStreet(Record* table, size_t table_size);
void searchStreetLinear(Record *table, size_t table_size, const char *target_street, bool printFlagLinearSearch);
void searchStreet(IndexEntry **index, const char *target_street, bool printFlagHashIndexSearch);
void free_index(IndexEntry **index_on_street);
void free_table();
int count_unused_slots(IndexEntry **index_on_street);

#endif