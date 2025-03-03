# Banishbot
This is my fork on [Dave Churchill's Starcraft bot](https://www.youtube.com/watch?v=czhNqUxmLks).

# Summary
This is a Zerg AI with the goal of approaching the game like a pro player.  Being able to read a build order off of TeamLiquid and playing it out to the best of its abilities. (Abstracting the execution from the goal).  I also intend to have it beat human opponents.  It will execute some tasks beyond human capabilities:
- Muta micro
- Nydus canal utilization
- Worker splitting
- etc

The abstraction between order and execution means I can implement a generic muta micro method and then when the build order creates mutas the AI will use them appropriately.

An [example](https://liquipedia.net/starcraft/2_Hatch_Muta_(vs._Protoss)) of a build order looks like:
```
9 - Overlord
12 — Hatchery @ expansion
12 — Scout
11 — Spawning Pool
12 — Extractor
12 — Save Larvae (see note)
@100% Pool — 8 Zerglings
@150 Minerals / 100 Gas — Lair
16 — Overlord
@100 Minerals / 100 Gas — Zergling Speed
NOTE — Make Drones when possible (see note)
@100% Lair — Spire
@100% Lair — Send Drone to take 3rd Base (see note)
26 — Hatchery @ 3rd Gas
25 — Extractor
26 — 2 Overlords
@350 hp — Save Larva on both Hatcheries for Mutalisks
@100% Spire - 6 Mutalisks
If Protoss opened Stargate -> Corsair, build 2–4 Scourge (1–2 Eggs), and continue Mutalisk production
@100% Hatchery — Overlord at 3rd
@100% Hatchery — 4th Hatchery at Natural
```

This is a build meant for ZvP.  A 2 hatch Muta build that weighs on the users muta micro capabilities.  It needs to pick off "lone photon cannons, High Temps, dragoons and probes".

This build is complicated.  It has notes on how to do what are generic tasks, specifically.  It also includes notes of not just units/buildings to produce at certain supply thresholds but also tasks to perform and at resource thresholds.  But it sets a nice goal of what capabilities the bot should be able to accomodate.

# Setup Instructions:
(Provided by Dave Churchill)
## Windows / C++

STARTcraft comes with a StarterBot written in C++ using BWAPI 4.4.0. This repo comes with BWAPI, and uses Injectory to launch StarCraft with BWAPI, so Chaoslauncher is not required.

1. Download / Clone this repo to your computer
2. Download and unzip [Starcraft Broodwar 1.16.1](http://www.cs.mun.ca/~dchurchill/startcraft/scbw_bwapi440.zip) to the included `windows/starcraft` folder
3. Run `windows/RunC++BotAndStarcraft.bat` which will launch the bot executable and Starcraft / BWAPI
4. Open `windows/visualstudio/StartCraft.sln` in Visual Studio 2022 to modify / recompile the code
