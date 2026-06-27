About Singleton :
Singleton pattern is a design pattern which restricts a class to instantiate its multiple objects. It is nothing but a way of defining a class. 
Class is defined in such a way that only one instance of the class is created in the complete execution of a program or project. 

The folder contains the code for Singleton for the below 4 approaches :

Program starts
      │
      ├── Eager+Pointer    → constructor runs  ← before main
      ├── Eager+Reference  → constructor runs  ← before main
      │
      ▼
   main() starts
      │
      ├── Lazy+Pointer     → constructor runs  ← on first call
      └── Lazy+Reference   → constructor runs  ← on first call

Table for comparision.

+------------------+-------------------------+-------------------------+------------------+------------------+
|                  |   Lazy + Pointer        |  Lazy + Reference       | Eager + Pointer  | Eager + Reference|
|                  |                         |  (Meyers)               |                  |                  |
+------------------+-------------------------+-------------------------+------------------+------------------+
| When created     | First getInstance() call| First getInstance() call| Before main()    | Before main()    |
+------------------+-------------------------+-------------------------+------------------+------------------+
| How stored       | Singleton*              | local static            | Singleton*       | static member    |
+------------------+-------------------------+-------------------------+------------------+------------------+
| Returns          | pointer *               | reference &             | pointer *        | reference &      |
+------------------+-------------------------+-------------------------+------------------+------------------+
| Need delete      | Yes                     | No                      | Yes              | No               |
+------------------+-------------------------+-------------------------+------------------+------------------+
| Thread safe      | No                      | Yes                     | Yes              | Yes              |
+------------------+-------------------------+-------------------------+------------------+------------------+
| Best for         | Simple cases            | Modern C++              | Always needed    | Always needed    |
+------------------+-------------------------+-------------------------+------------------+------------------+
  
