# BanishBot Design Document

## Agents

### Knowledge Tracking
The bot will need to keep track of all information that the opponent has given him.  Any unit that he sees, he will know that the opponent must've built the required tech structures to build that unit.  Ex. If the bot sees a siege tank, we know that the opponent has built a barracks, factory and machine shop to build the siege tank.  Same goes for any unit.  This can be used to determine the state of the opponent.

### Crisis management
This is the portion of the bot responsible for watching out for threats such as a cheese or all in early in the game.  Later on it may look out for flanks, drops or a number of other unexpected attacks/pushes.  Maybe something like Dark Templars or another cloaked unit surprises the bot while it has no detection which may cause it to "panic" and therefore go into a defensive state where it needs to deal with the issue before resuming previous state.

### Macro Management
The Macro manager is in charge of following the build order, training units, building structures, setting rallys 

### Micro Management