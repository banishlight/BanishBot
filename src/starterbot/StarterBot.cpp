#include "StarterBot.h"
#include "Tools.h"
#include "MapTools.h"

StarterBot::StarterBot()
{
    stage = 0;
    workerMax = 30;
    enemybaseLocation;
}

// Called when the bot starts!
void StarterBot::onStart()
{
    // Set our BWAPI options here    
	BWAPI::Broodwar->setLocalSpeed(10);
    BWAPI::Broodwar->setFrameSkip(0);
    
    // Enable the flag that tells BWAPI top let users enter input while bot plays
    BWAPI::Broodwar->enableFlag(BWAPI::Flag::UserInput);

    // Call MapTools OnStart
    m_mapTools.onStart();
}

// Called on each frame of the game
void StarterBot::onFrame()
{
    // Update our MapTools information
    m_mapTools.onFrame();

    // Send our idle workers to mine minerals so they don't just stand there
    sendIdleWorkersToMinerals();

    // Train more workers so we can gather more income
    //trainAdditionalWorkers();

    // Build more supply if we are going to run out soon
    //buildAdditionalSupply();

    // Draw unit health bars, which brood war unfortunately does not do
    Tools::DrawUnitHealthBars();

    // Iterate over our Build Order
    BasicOrder();

    // Draw some relevent information to the screen to help us debug the bot
    drawDebugInformation();
}

// Send our idle workers to mine minerals so they don't just stand there
void StarterBot::sendIdleWorkersToMinerals()
{
    // Let's send all of our starting workers to the closest mineral to them
    // First we need to loop over all of the units that we (BWAPI::Broodwar->self()) own
    const BWAPI::Unitset& myUnits = BWAPI::Broodwar->self()->getUnits();
    for (auto& unit : myUnits)
    {
        // Check the unit type, if it is an idle worker, then we want to send it somewhere
        if (unit->getType().isWorker() && unit->isIdle())
        {
            // Get the closest mineral to this worker unit
            BWAPI::Unit closestMineral = Tools::GetClosestUnitTo(unit, BWAPI::Broodwar->getMinerals());

            // If a valid mineral was found, right click it with the unit in order to start harvesting
            if (closestMineral) { unit->rightClick(closestMineral); }
        }
    }
}

// Train more workers so we can gather more income
void StarterBot::trainAdditionalWorkers()
{
    const BWAPI::UnitType workerType = BWAPI::Broodwar->self()->getRace().getWorker();
    const int workersWanted = workerMax;
    const int workersOwned = Tools::CountUnitsOfType(workerType, BWAPI::Broodwar->self()->getUnits());
    if (workersOwned < workersWanted)
    {
        // get the unit pointer to my depot
        const BWAPI::Unit myDepot = Tools::GetDepot();

        // if we have a valid depot unit and it's currently not training something, train a worker
        // there is no reason for a bot to ever use the unit queueing system, it just wastes resources
        // && !myDepot->isTraining()
        if (myDepot ) { myDepot->train(workerType); }
    }
}

// Build more supply if we are going to run out soon
void StarterBot::buildAdditionalSupply()
{
    // Get the amount of supply supply we currently have unused
    const int unusedSupply = Tools::GetTotalSupply(true) - BWAPI::Broodwar->self()->supplyUsed();

    // If we have a sufficient amount of supply, we don't need to do anything
    if (unusedSupply >= 2) { return; }

    // Otherwise, we are going to build a supply provider
    const BWAPI::UnitType supplyProviderType = BWAPI::Broodwar->self()->getRace().getSupplyProvider();

    const bool startedBuilding = Tools::BuildBuilding(supplyProviderType);
    if (startedBuilding)
    {
        BWAPI::Broodwar->printf("Started Building %s", supplyProviderType.getName().c_str());
    }
}

// Draw some relevent information to the screen to help us debug the bot
void StarterBot::drawDebugInformation()
{
    BWAPI::Broodwar->drawTextScreen(BWAPI::Position(10, 10), "Hello, World3!\n");
    Tools::DrawUnitCommands();
    Tools::DrawUnitBoundingBoxes();
}

// Called whenever the game ends and tells you if you won or not
void StarterBot::onEnd(bool isWinner)
{
    std::cout << "We " << (isWinner ? "won!" : "lost!") << "\n";
}

// Called whenever a unit is destroyed, with a pointer to the unit
void StarterBot::onUnitDestroy(BWAPI::Unit unit)
{
	
}

// Called whenever a unit is morphed, with a pointer to the unit
// Zerg units morph when they turn into other units
void StarterBot::onUnitMorph(BWAPI::Unit unit)
{
	
}

// Called whenever a text is sent to the game by a user
void StarterBot::onSendText(std::string text) 
{ 
    if (text == "/map")
    {
        m_mapTools.toggleDraw();
    }
}

// Called whenever a unit is created, with a pointer to the destroyed unit
// Units are created in buildings like barracks before they are visible, 
// so this will trigger when you issue the build command for most units
void StarterBot::onUnitCreate(BWAPI::Unit unit)
{ 
	
}

// Called whenever a unit finished construction, with a pointer to the unit
void StarterBot::onUnitComplete(BWAPI::Unit unit)
{
	
}

// Called whenever a unit appears, with a pointer to the destroyed unit
// This is usually triggered when units appear from fog of war and become visible
void StarterBot::onUnitShow(BWAPI::Unit unit)
{ 
	
}

// Called whenever a unit gets hidden, with a pointer to the destroyed unit
// This is usually triggered when units enter the fog of war and are no longer visible
void StarterBot::onUnitHide(BWAPI::Unit unit)
{ 
	
}

// Called whenever a unit switches player control
// This usually happens when a dark archon takes control of a unit
void StarterBot::onUnitRenegade(BWAPI::Unit unit)
{ 
	
}

void StarterBot::increaseWorkerMax(int increase)
{
    workerMax += increase;
}

void StarterBot::buildSpawningpool()
{
    BWAPI::Broodwar->drawTextScreen(BWAPI::Position(10, 15), "Building Spawning pool!\n");
    Tools::BuildBuilding(BWAPI::UnitTypes::Zerg_Spawning_Pool);
}

bool isSpawningPoolInProgress() {
    for (auto u : BWAPI::Broodwar->self()->getUnits()) {
        if (u->getType() == BWAPI::UnitTypes::Zerg_Spawning_Pool &&
            u->isBeingConstructed()) {
            return true;
        }
    }
    return false;
}

void trainOverlord() {
    for (auto u : BWAPI::Broodwar->self()->getUnits()) {
        // Check if the unit is a Zerg Larva
        if (u->getType() == BWAPI::UnitTypes::Zerg_Larva) {
            // Issue the command to morph the Larva into an Overlord
            u->morph(BWAPI::UnitTypes::Zerg_Overlord);
            // Break out of the loop once an Overlord has been started
            break;
        }
    }
}

void trainZerglings() {
    for (auto u : BWAPI::Broodwar->self()->getUnits()) {
        // Check if the unit is a Zerg Larva
        if (u->getType() == BWAPI::UnitTypes::Zerg_Larva) {
            // Issue the command to morph the Larva into a Zergling
            u->morph(BWAPI::UnitTypes::Zerg_Zergling);
            // Break out of the loop once a Zergling has been started
            break;
        }
    }
}

void scoutEnemyBaseLocations() {
    //Check if 4 player or 2 player map, if 2 player, immediately return the position.

    // Get list of possible start locations
    auto startLocations = BWAPI::Broodwar->getStartLocations();

    // Check if we have more than 3 lings
    int lingCount = 0;
    for (auto u : BWAPI::Broodwar->self()->getUnits()) {
        if (u->getType() == BWAPI::UnitTypes::Zerg_Larva) {
            lingCount += 1;
        }
    }
    if (lingCount >= 3) {
        // Sufficient amount of lings, send scouts
    }
    else {
        // Not enough lings
        return;
    }
    // Scout all possible starting locations

    // save enemy base location

}

void sendScout(BWAPI::Position scoutLocation) {

}



void StarterBot::BasicOrder()
{
    BWAPI::Broodwar->drawTextScreen(BWAPI::Position(10, 0), "Stage: %d", stage);
    switch (stage) 
    {
    case 0: // Initial state, build workers
        trainAdditionalWorkers();
        if (BWAPI::Broodwar->self()->supplyUsed() == 18) {
          stage = 1;
        }
        break;
    case 1:
        //BWAPI::Broodwar->drawTextScreen(BWAPI::Position(10, 15), "Stage 2!\n");
        buildSpawningpool();
        if (isSpawningPoolInProgress()) {
          stage = 2;
        }
        break;
    case 2:
        //buildAdditionalSupply();
        trainOverlord();
        if (Tools::GetTotalSupply(true) == 34) {
         stage = 3;
        }
        break;
    case 3: {
        // increaseWorkerMax(9);
        trainAdditionalWorkers();
        BWAPI::UnitType workerType = BWAPI::Broodwar->self()->getRace().getWorker();
        int workersOwned = Tools::CountUnitsOfType(workerType, BWAPI::Broodwar->self()->getUnits());
        if (workersOwned == 12) { stage = 4; }
    }
        break;

    case 4:
        trainZerglings();
        break;

    default:
        //BWAPI::Broodwar->drawTextScreen(BWAPI::Position(10, 15), "Defaulting");
        increaseWorkerMax(0);
    }


}