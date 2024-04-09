/*

    5 minutes of Engineering Video : 

    Rules : 
        Arrow always points to parent....
        
        Inheritance arrow is ---------------> [Arrow is hollow but the line is solid]

        If function is written : 
            withdrawal(amount : dollars)
            
    Abstract Class : If there is a function name in italic order = it means class is abstract..


    Bidirectional Association : 
        For eg. : 
            Plane and Flight OOPS
            Solid line with no head indicates bidirctional association...[sometimes it may be one-directional]

            Flight ---------------------- Plane


    Unidirectional Association : 

        For eg: 

            [Balance se jyada nikalna...negative m jana] 

            OverdrawnAccountReport   ---------------------->         Account          
            generatedOn() : date
            refresh()

        Notation :     Simpler Arrow [arrow represent known thing...]   [Check once !!]

    Cardinality Value...

    0..1             Zero or One
    1                One only
    0..              Zero or more
    1..*             One or more


        Interfaces: 

            Dotted line with hollow arrow indicates interfaces.. [ -----------> ]
            In interface class, interface is written on it..

    Aggregation : 
        One car has a set of 4 wheels.....
            4 wheels ---> 4 object

        Car object delete but we may kept wheels data...
        
        For eg : 
            Employee has a project..
            So, if employee leaves the job then it will not affect or stop the project..

            <>--------------->    [solid line]

            
            Solid line from the parent class to part class, and drew an unfilled diamond
                shape on parent's class association end..

 
    Company and Department                           BankAccount and DebitCard

            Company <>-----------------> Department (1..*)
                Diamond is filled....(solid line).....(simple arrow)
*/
