/*
    Why ?? 

    lscpu | less   ---------> command of terminal to show details of the system

    Processor : 
        It is a silicon chip which contains Registers, Cache etc...
            Eg : Intel / Ryzen / Snapdragon etc..
                Works in cycles...
                    Clock Speed is directly proportional to execute instruction per second...
    
    Cores :
        They are the physical section inside the processor 
            Each core is capable of hanling ONE PROCESS !!
                Eg : Open VS Code and Firefox ----> needs two cores
                    One core handle one process
                        Important : Each cores may have same or different clock speed..

    Clock Speed :
        Insturctions per second is known as Clock Speed..
            Clock Speed is directly proportional to execute instruction per second...
                For eg : 
                    4.8 GHz  ----> 4.8 * 10 ^ 9 instruction per seconds..

    Thread :
        Set of instructions that occupy memory and represent one isolated, independently
            executable section of process..

    How to check how many process will run in my system...?
        Ans : terminal command ------> top   and press enter

    Important : 
        When I check our system, then tasks is around 300+ 
            When you turned on your system, it is almost 300+

        But the main thing is : My system supports only 10 cores
            So, how it is possible to manage 300+ process by using 10 cores ?

                Ans : CPU Scheduling Algorithm

    Working :
        For eg : Every process gets 1 unit of time before it is switched for a different process..

            Kismat khrab condition :
                ./app : Process got 1 unit of time
                    Before 1 unit of time has passed, if there is delay ( I/O, CPU delay )...

    Why we create Threads in our code..?
        To make the use of 1 unit properly, thread is used..
            Context switching ..... pending !!

        We cannot force OS, but we will increase the choice for OS to make thread of
            functions..

    For eg : 
        1) void F1() { user input; square}

        2) void F2() {first 5 natural number square }

    Important : Main function has its own thread...

        Best Cases : 
            If my CPU has 4 cores :
                May be 3 threads get mapped to 3 cores, no one is waiting !!

        Average Case:
            May be 2 threads get mapped to 2 cores, 1 is waiting !!
*/


#include<iostream>
#include<thread>      // mandatory

void Square(int* arr, std::size_t N){
    for(int i=0;i<N;i++){
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << " Square of numbers is : "<< arr[i] * arr[i] << " \n ";
    }
}

void Cube(int* arr, std::size_t N){
    for(int i=0;i<N;i++){
        std::this_thread::sleep_for(std::chrono::seconds(1));   // Greek word
        std::cout << " Cube of numbers is : "<< arr[i] * arr[i]* arr[i] << "  \n";
    }
}

int main(){
    int arr[] = {1,2,3,4,5};

    // Square(arr, 5);
    // Cube(arr,5);

    std::thread t1(&Square, arr, 5);
    std::thread t2(&Cube, arr,5 );

    // After creattion of t2, many scenarios can be encountered !!

    // Scenario 1: t1 is already completed by the time t2 is even started
    // Scenario 2: t1 and t2 are yet to be completed and running in the background


    if(t1.joinable()){
        t1.join();      // main thread should now wait till t1 is finished !! [ block till t1 is finished !! ]
    }

    if(t2.joinable()){
        t2.join();     // main thread should now wait till t2 is finished !! [ block till t2 is finished !! ]
    }

    std::cout << "Goodbye\n";
}

/*
                     MAIN THREAD

                                            ------------------------------------>\
                                                                                  \
            START ------------------------>         ----------------------->   --------------->
                                    [ t1 is created ]         [ t2 created]   /
                                    |                                        /
                                    |                                       /
                                    |                                      /
                                    ---------> cout & sleep ------------->/
                                    [ t1 ]

            NOte : You have to end the main thread at the end - Developer's Responsibility
*/

/*
                                    DEDICATED MEMORY SPACE

        Buffers : 

        SCREEN   ---------------------->   [ OUTPUT TEXT ]

        cout ----------> means sending the data to buffer
        Hello, World -----------> BUFFER                                 SCREEN
                                                                        [ OUTPUT TEXT ]
        
        IMP : 
            EVERY PROCESS GET ONE BUFFER FOR STDOUT
                Here, in this condition we have to std::cout statements, then Race Condition occurs...
                    [  Square | Cube  << 1 << 3 << Square << ......]

                Race Condition : 
                    IT OCCURS IN THE CRITICAL SECTION ONLY...
                        SOLUTION :
                            Semaphores and Mutex...

        # Important : 
            There is only one buffer for one application ( like ./out or ./app or any name have only one buffer)...

*/
