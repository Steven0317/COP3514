#ifndef dogs_h

#define NAME_LEN 30

struct dog{
	int number;
	char dog_name[NAME_LEN + 1];
	char owner_last_name[NAME_LEN + 1];
	char breed[NAME_LEN + 1];
	struct dog *next;
};

struct dog *append(struct dog *list);
void search(struct dog *list);
void print(struct dog *list);
void clear(struct dog *list);
struct dog *delete_from_list(struct dog *list);


#endif
