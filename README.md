# Philosophers

The purpose of this project is: **to teach you how deal with UNIX threads and things in between.**


## So how can we create a thread ?

- pthread_create function allows you to create a thread in c
- - `pthread_create(struct, args, function, args);`
- - struct is where to store thread information and it defining like that `pthread_t thread_name`
- - args is the argument of the thread *Since its a pointer we can pass it `NULL` and it will take default arguments*