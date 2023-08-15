# PROJECT: 0x0E. C - Structures, typedef


## Tasks


**Question #0, File: dog.h**

```c
/* Declares a struct 'dog' with required members */
struct dog {
  char *name; 
  float age;
  char *owner;
};
```
- Declares struct dog with required members

**Question #1, File: 1-init_dog.c**

```c
/* Handles NULL pointer and initializes members from parameters */
void init_dog(struct dog *d, char *name, float age, char *owner) 
{
  /* Check for NULL and malloc if needed */
  if (d == NULL)
    d = malloc(sizeof(struct dog));

  /* Use dot syntax to access members */
  d->name = name;
  d->age = age;
  d->owner = owner;
}
```
- Handles NULL pointer 
- Uses dot syntax to access members
- Initializes members from parameters

**Question #2, File: 2-print_dog.c**

```c
/* Checks for NULL, prints placeholders, and prints members properly */  
void print_dog(struct dog *d)
{
  /* Check for NULL dog */
  if (d == NULL)
    return;

  /* Print placeholder strings for NULL members */
  if (d->name == NULL)
    d->name = "(nil)";
  if (d->owner == NULL)
    d->owner = "(nil)";   

  /* Print each member with proper format specifier */
  printf("Name: %s\n", d->name);
  printf("Age: %f\n", d->age);
  printf("Owner: %s\n", d->owner);
}
```

- Checks for NULL dog and members
- Prints placeholders for NULL members  
- Prints members with proper format specifiers

**Question #3, File: dog.h**

```c
/* Typedefs struct dog as dog_t */
typedef struct dog dog_t;
```
- Typedefs struct dog as dog_t

**Question #4, File: 4-new_dog.c** 

```c  
/* Dynamically allocates memory, copies strings, handles errors */
dog_t *new_dog(char *name, float age, char *owner)
{
  dog_t *dog = malloc(sizeof(dog_t));
  if (dog == NULL)
    return NULL;

  dog->name = strcpy(dog->name, name);
  dog->owner = strcpy(dog->owner, owner);  
  dog->age = age;

  return dog;
}
```

- Dynamically allocates memory for struct
- Handles malloc failure 
- Copies name and owner strings
- Sets age member
- Returns new dog or NULL

**Question #5, File: 5-free_dog.c**

```c
/* Frees members and struct, handles NULL pointer */
void free_dog(dog_t *d) {
  if (d == NULL)
    return;
  
  free(d->name);
  free(d->owner);
  free(d);
}
``` 

- Handles NULL pointer
- Frees each member pointer
- Frees struct pointer


