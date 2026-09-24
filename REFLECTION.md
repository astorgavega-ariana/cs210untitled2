# Reflection Questions


1. In LinkedList::deleteFront(), why does it take two separate delete calls instead of one?
Name exactly what each one frees, and name the two new calls back in the program responsible
for putting them on the heap in the first place.
- For this particular function it's taking 2 seperate delete calls because the first delete call is grabbing data to delete it aka
basically storing it and then the second call is deleting it again because when you take out the data of a node the node is still there
so in order to delete it (it being the node) you must call a seperate delete call! I'm guessing the two new calls back in the program
in 'new Node<T>' by addFront() fucntion where its first creating this new node and then added value inside that is then deleted later like in main
'list->addFront(new int(10))'. 

2. ArrayList never had a destructor before today. Explain, in your own words, why switching
   from T data[CAPACITY] to T* data [CAPACITY] is what made a destructor necessary, and what
   would happen if you forgot to write one. Would you get a compiler error? Why or why not?
- By switching from T data to T* data we are refrencing the actual value in the destructor and not the address of that
value itself! So if we were not to change it to T* then instead the deconstructor would've deleted the address that
leads to the actual value making it really bad becasue then we can't access T* at all if the address is gone I believe.
I guess this would be likely a compile error because the compliler is essentially the "checker" for the code and the code must need
a memory address that is valid I'd assume. I haven't actually tested it yet. 

3. search() and addFront() both take a T*, but they treat that pointer completely differently.
   Explain the difference in terms of ownership: which one is allowed to delete what you hand it,
   and which one is never allowed to?
- When it comes to addFront() the function takes the T* value and uses it in the line 'Node<T>* fresh = new Node<T>(value)' whilst 
the search() function uses the value and instead uses it in 'Node<T>* current = head_'. From comparing the two at "face value" it's pretty obvious that
the addFront() function is using the T* to make a new node which is being added to the front of the LinkedList hence the addFront() function. Compared to 
search(), this function uses T* to start at the first node(but isn't creating a new one) which is the head node and then cycles through (searching). For ownership because
of these different uses, addFront() T* will never be able to delete if handed since it only creates New and search() can since it selects and acceses a node itself.

4. You swapped LinkedList<T> for ArrayList<T> inside makeList() and reran main.cpp without
   changing a single line there. What two mechanisms, by name, made that possible?
- I'm guessing because LinkedList and ArrayList are essentially working very similarly even if logically they are pretty different
with arrays not having pointers and LinkedLists having a head and tail etc etc, but since they are similar enough when it comes to
being lists and string data with my best guess would be that makeList() is using ArrayList the same way it would LinkedList using it as a form of
polymorphism/abstraction with T value!

5. Pick one keyword from the Key Terms glossary that you either had to add today or wouldn’t have
   thought to add on your own (explicit, override, virtual, const, or any other). Describe, in
   your own words and without copying the guide’s wording, the smallest example you can think
   of where leaving it out would cause a real problem.
- I am choosing the keyword 'virtual destructor' from the glossary which in my mind is just the official keyterm to label the garbage collector
  inside c++ especially when dealing with memory inside of c++ and its limited space. In this case, when we are deleting from deleteFront() when using LinkedLists,
  if we were not to use the 'virtual destructor' aka delete func. then when we'd "delete" a node the node itself would still be there and take up space but by using
  the destructor we make sure to compellty get rid of it and free up space in the memory for further use on the same program! IF we didn't use this then we could end up in a situation with
a lot of empty nodes just taking up memory space.