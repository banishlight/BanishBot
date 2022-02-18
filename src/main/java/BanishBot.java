import bwapi.*;
import bwta.BWTA;
import bwta.BaseLocation;

public class BanishBot extends DefaultBWListener{
    private BWClient bwClient;
    private Game game;
    private Player self;

    @Override
    public void onStart(){
        game = bwClient.getGame();
        self = game.self();


    }

    @Override
    public void onFrame(){
        game.drawTextScreen(100, 100, "BanishBot v1.0!");
        // Train units while we can
        for (Unit trainer : self.getUnits()) {
            UnitType unitType = trainer.getType();
            if (unitType.isBuilding() && !unitType.buildsWhat().isEmpty()) {
                UnitType toTrain = unitType.buildsWhat().get(0);
                if (game.canMake(toTrain, trainer)) {
                    trainer.train(toTrain);
                }
            }
        }
    }


    void run() {
        bwClient = new BWClient(this);
        bwClient.startGame();
    }

    public static void main(String[] args) {
        new BanishBot().run();
    }

    public void onUnitComplete(Unit unit) {
        if (unit.getType().isWorker()) {
            Unit closestMineral = null;
            int closestDistance = Integer.MAX_VALUE;
            for (Unit mineral : game.getMinerals()) {
                int distance = unit.getDistance(mineral);
                if (distance < closestDistance) {
                    closestMineral = mineral;
                    closestDistance = distance;
                }
            }
            // Gather the closest mineral
            unit.gather(closestMineral);
        }
    }
}
