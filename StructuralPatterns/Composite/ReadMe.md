### Intent
Compose objects into tree like structures to represent part whole hierarchies.
Composite pattern lets the client treat an indivisual objects and  composition of objects uniformly.

#### Applicability
Use the Composite pattern when
• you want to compose objects into tree structures to represent part-whole hierarchies of objects.
• you want clients to be able to ignore the difference between compositions of
objects and individual objects. Clients will treat all objects in the composite
structure uniformly.

#### Participants

##### Component
 - declares the interface  for objects in the composition
 - implements default behaviour for the interfaces common to all classes

##### Leaf
 - Represent the leaf object in the composition

##### Composite

##### Client
 - manipulates the objects in the composition through component interface


One of the issues in the implementation is how to differentiate between leaf and the composite objects without specifying the methods that are specific to only composite in both the leaf and composite classes

to solve this issue

specify the Composite* GetComposite() {return 0} in the component class and then override this method in the composite class like
Composite* GetComposite() { return this; } and dont override this in the leaf class;

doing this we will have transparency as both the leaf and the composite will still have the same interface