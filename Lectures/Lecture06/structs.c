/**
 * structs.c
 *
 * Tests structs, dynamic allocation, and arg passing.
 *
 * Compile: gcc -g -Wall -o structs structs.c
 * Run    : ./structs
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bank_record {
	int id;
	char last_name[100];
	char first_name[100];
	double balance;
};

/* We can also pass the struct directly. Note the dot "." notation */
void print_name(struct bank_record record);

/* This version of the print function takes a pointer to a struct instead */
void print_name2(struct bank_record *record);

void increase_balance(struct bank_record *record, float amount);

struct bank_record copy_rename(struct bank_record record, char *new_name);

int main(void) {
	/* Statically allocating a pre-populated struct: */
	struct bank_record record1 = {1, "Stark", "Tony", 6500000.0};

	/* Dynamic allocation */
	struct bank_record *record2;
	record2 = calloc(8, sizeof(struct bank_record));
	record2->id = 2;
	strcpy(record2->last_name, "Arslan");
	strcpy(record2->first_name, "Alperen");
	record2->balance = 70000000.0;

	// free(record2); <-- what happens if we free "record2" here?
	
	print_name2(record2);
	print_name2(&record1);
	print_name(*record2);
	fprintf(stdout, "id: %d\n", record2->id);

	/* Let's give Tony $500000 */
	increase_balance(&record1, 500000);

	/* and $10000000 to Alperen */
	increase_balance(record2, 10000000);
	/* (Note the ampersand) */

	/* Now we'll pass these structs by value. Note the pointer dereference */
	print_name(record1);
	print_name(*record2);

	/* Finally, let's return a struct by value. This essentially creates a copy */
	struct bank_record record3 = copy_rename(record1, "Pepper");
	print_name(record1);
	print_name(record3);

	free(record2);

	return EXIT_SUCCESS;
}

void print_name(struct bank_record record) {
	printf("Name: %s, %s\n",
		record.last_name,
		record.first_name);
}

void print_name2(struct bank_record *record) {
	printf("Name: %s, %s\n",
		record->last_name,
		record->first_name);
}

void increase_balance(struct bank_record *record, float amount) {
	if (amount <= 0) {
		printf("Amount must be greater than 0!");
		return;
	}

	double new_balance = record->balance + amount;

	printf("Increasing the balance of %s, %s (Account %d) from %f to %f\n",
		record->last_name,
		record->first_name,
		record->id,
		record->balance,
		new_balance);

	record->balance += amount;
}

struct bank_record copy_rename(struct bank_record record, char *new_name) {
	strcpy(record.first_name, new_name);
	return record;
}
