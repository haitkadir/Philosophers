# Philosophers

The purpose of this project is: **to teach you how to deal with UNIX threads and things in between.**


### So how can we create a thread ?

- pthread_create function allows you to create a thread in c
 - `pthread_create(thread_id, params, function, args);`
 - `thread_id` is where to store thread information and it defining like that `pthread_t thread_name`
 - `params` is the parameters of the thread <strong style="font-family: Operator Mono">Since its a pointer we can pass it `NULL` and it will take default params</strong>
 - `function`or `routine` is the function to be excuted with this thread
 - `args` is the argument to pass to the function that will be excuted *We can set it to `NULL` if that function don't take arguments*

### Now we created a thread we have to wait it until it completes excution before we exit the program but how ?

- pthread_join waits for the thread til it complete its jobe
 - `pthread_join(thread_id, arg);`
 - `thread_id` is the thread we wait for
 - `arg` is the return of routine function *We can set it to `NULL` if that function don't return arguments*

- function marks the thread identified by
       thread as detached.  When a detached thread terminates, its
       resources are automatically released back to the system without
       the need for another thread to join with the terminated thread
 - `pthread_join(thread_id, arg);`
 - `thread_id` is the thread we wait for
 - `arg` is the return of routine function *We can set it to `NULL` if that function don't return arguments*

### What is the diffrence between `pthread_join(thread_id, arg);` and `pthread_detach(thread_id);`
- The default state of creating a thread is joinable. If a thread finishes running but is not joined,
- its state is similar to the Zombie Process in the process,
- that is, there are still some resources that have not been recycled (exit status code),
- so the thread creator should Call pthread_join to wait for the thread to finish,
- and get the thread's exit code, reclaim its resources (similar to wait, waitpid), 
- but after calling pthread_join(pthread_id), if the thread does not end, the caller will be blocked,
- in some cases We don’t want this. For example, in the Web server, when the main thread creates a child thread for each new link to process,
- the main thread does not want to be blocked by calling pthread_join (because it will continue to process incoming links ),
- then you can add code `pthread_detach(thread_id)` from the parent thread (non-blocking, return immediately).
- This sets the status of the child thread to detached, then after the thread runs All resources will be released automatically.

## Dining Philosopher Problem
![alt text](https://upload.wikimedia.org/wikipedia/commons/7/7b/An_illustration_of_the_dining_philosophers_problem.png)
