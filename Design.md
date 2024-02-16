# BanishBot Design Document

## Agents
The structuring of the bot and sub modules may be constructed in such a way to create a priority queue of tasks that need to be carried out.  If something urgent like a cheese detected may override the priority list but outside of that it will carry out the tasks needed.  The build order tasks will be higher priority than the automated tasks.  If the bot has built 6 lings according to the build but it has no specifics on how to use them, the bot may use one to scout the opponent while the build carries forward.

### Knowledge Tracking
The bot will need to keep track of all information that the opponent has given him.  Any unit that he sees, he will know that the opponent must've built the required tech structures to build that unit.  Ex. If the bot sees a siege tank, we know that the opponent has built a barracks, factory and machine shop to build the siege tank.  Same goes for any unit.  This can be used to determine the state of the opponent.

### Crisis management
This is the portion of the bot responsible for watching out for threats such as a cheese or all in early in the game.  Later on it may look out for flanks, drops or a number of other unexpected attacks/pushes.  Maybe something like Dark Templars or another cloaked unit surprises the bot while it has no detection which may cause it to "panic" and therefore go into a defensive state where it needs to deal with the issue before resuming previous state.

### Macro Handler
The Macro handler is in charge of following the build order to train units, build structures and, set rallys. 

### Micro Handler


### Build Order Parsing
Parsing the build order and organizing it into something the bot can traverse will be an important module.  For now the build order is a switch case statement that once a condition is satisfied it will iterate onto the next stage of the build.  This build order is much more explicit than the example human read one as it has to carry out each specific task.  The future build order parser will construct a tree like structure for the bot to traverse as the game advances.  The trees branchs will either be a default or conditional branch.  Where a conditional branch is instruction given to the bot to carry out if the condition is met.  Such as if a cannon rush is detected, the bot may halt what it's doing to stop the cannon rush and then find some way to continue out the game.  Carrying on with the idea of this cannon rush and abstraction and automation of action, in the future the bot may have an automatic cannon rush handler and it will not need to be explicitly checked and handled for within the build order (again, similar to how a human may handle it.  As a human player learns how to play starcraft they will learn how to transition their build into stopping a cannon rush and transition out of handling it to close out the game).  