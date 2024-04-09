/*

    RAII : Resource Acquisition Is Initialization (principle)

    Whatever my program accesss to complete its oparations are basically called "Resources"
            -Heap Memory
            -File
            -Network Connnections
            -Semaphores/ Mutexes

    For example :
        void Magic(){
            int* ptr = (int*)malloc(20);
            Customer* c = new Customer();

            //Another simple method : 

            Example(ptr, c);
            free(ptr);
            free(c);

            But in this case, what if example throws exception ?

                Now put this into try catch block...
                    So, we don't free the memory in try block because if example throws 
                        error then again it doesn't work...

                Now, what we do - We free the memory after try-catch block...
                    No, this is also not a good practise


                Best solution is : template 

                template <typename T>
                class Wrapper{
                    private:
                        T* m_ptr;

                        Wrapper(T*p) : m_ptr{p}

                    public:
                    ~Wrapper(){
                        delete m_ptr;
                    }
                }


                Now, change void magic code like this...[Resource Acquistion Is Initialization]

                void Magic(){
                    Wrapper c(new Customer());
                }

        }

        void Demo(){
            free(ptr);                            // [ Won't work ]
        }













*/
