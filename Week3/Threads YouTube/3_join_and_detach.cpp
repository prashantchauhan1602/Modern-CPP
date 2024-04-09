/*
    Join :
        Once a thread is started we wait for this thread to finish by calling join() function on thread object...
        NOTE : Double join will result an error...
        We can also check whether the thread is joinable or not by using joinable() function...

    Detach : 
        Parent Thread -----> Main Thread ( in example )
        In this, it is not wait for given 5 seconds..

        Used to detach newly created thread from parent thread.. 
        Double detach will leads to program termination...
            But if you first detach first thread...
                Again, you want to check if the thread is joinable or not and then detach again...
                
        If we have detach thread and main function is returning , then the detached thread execution is suspended...
*/