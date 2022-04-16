# Philosophers

The purpose of this project is: **to teach you how to deal with UNIX threads and things in between.**


## So how can we create a thread ?

- pthread_create function allows you to create a thread in c
- - `pthread_create(struct, params, function, args);`
- - struct is where to store thread information and it defining like that `pthread_t thread_name`
- - params is the parameters of the thread <strong style="font-family: Operator Mono">Since its a pointer we can pass it `NULL` and it will take default params</strong>
- - function is the function to excute with this thread
- - args is the argument to pass to the function that will be excuted *We can set it to `NULL` if that function don't take arguments*

## Now we created a thread we have to wait it until it completes excution before we exit the program but how ?

- pthread_join waits for the thread til it complete its jobe
