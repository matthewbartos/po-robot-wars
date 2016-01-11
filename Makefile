all: tournament

tournament: ./robots/creator.cc.o ./robots/robot.cc.o ./robots/miner.cc.o ./robots/warehouse.cc.o ./robots/transporter.cc.o ./robots/builder.cc.o ./exceptions/badformatexception.cc.o ./fields/field.cc.o ./fields/fieldsfactory.cc.o ./infXXXXXX/masterrobot.cc.o ./commands/loadworld.cc.o ./commands/rungame.cc.o ./commands/exit.cc.o ./commands/setplayer.cc.o ./commands/test.cc.o ./commands/setgameout.cc.o ./commands/liststudents.cc.o ./logic/game.cc.o ./logic/resourceset.cc.o ./actions/create.cc.o ./actions/build.cc.o ./actions/mine.cc.o ./actions/move.cc.o ./actions/anyrobotaction.cc.o ./actions/transfer.cc.o ./actions/action.cc.o ./infYYYYYY/masterrobot.cc.o ./main.cc.o
	g++ -std=c++11 -o tournament ./robots/creator.cc.o ./robots/robot.cc.o ./robots/miner.cc.o ./robots/warehouse.cc.o ./robots/transporter.cc.o ./robots/builder.cc.o ./exceptions/badformatexception.cc.o ./fields/field.cc.o ./fields/fieldsfactory.cc.o ./infXXXXXX/masterrobot.cc.o ./commands/loadworld.cc.o ./commands/rungame.cc.o ./commands/exit.cc.o ./commands/setplayer.cc.o ./commands/test.cc.o ./commands/setgameout.cc.o ./commands/liststudents.cc.o ./logic/game.cc.o ./logic/resourceset.cc.o ./actions/create.cc.o ./actions/build.cc.o ./actions/mine.cc.o ./actions/move.cc.o ./actions/anyrobotaction.cc.o ./actions/transfer.cc.o ./actions/action.cc.o ./infYYYYYY/masterrobot.cc.o ./main.cc.o
robots/creator.cc.o: robots/creator.cc robots/creator.h robots/robot.h \
 logic/resourceset.h resources/diamond.h resources/resource.h \
 resources/gold.h resources/metal.h resources/oil.h logic/game.h
	g++ -std=c++11 -I. -c ./robots/creator.cc -o ./robots/creator.cc.o
robots/robot.cc.o: robots/robot.cc robots/robot.h logic/resourceset.h \
 resources/diamond.h resources/resource.h resources/gold.h \
 resources/metal.h resources/oil.h logic/game.h robots/builder.h \
 robots/concreteminer.h robots/miner.h robots/creator.h \
 robots/transporter.h robots/warehouse.h
	g++ -std=c++11 -I. -c ./robots/robot.cc -o ./robots/robot.cc.o
robots/miner.cc.o: robots/miner.cc robots/miner.h robots/robot.h \
 logic/resourceset.h resources/diamond.h resources/resource.h \
 resources/gold.h resources/metal.h resources/oil.h logic/game.h
	g++ -std=c++11 -I. -c ./robots/miner.cc -o ./robots/miner.cc.o
robots/warehouse.cc.o: robots/warehouse.cc robots/warehouse.h \
 robots/robot.h logic/resourceset.h resources/diamond.h \
 resources/resource.h resources/gold.h resources/metal.h resources/oil.h \
 logic/game.h
	g++ -std=c++11 -I. -c ./robots/warehouse.cc -o ./robots/warehouse.cc.o
robots/transporter.cc.o: robots/transporter.cc robots/transporter.h \
 robots/robot.h logic/resourceset.h resources/diamond.h \
 resources/resource.h resources/gold.h resources/metal.h resources/oil.h \
 logic/game.h
	g++ -std=c++11 -I. -c ./robots/transporter.cc -o ./robots/transporter.cc.o
robots/builder.cc.o: robots/builder.cc robots/builder.h robots/robot.h \
 logic/resourceset.h resources/diamond.h resources/resource.h \
 resources/gold.h resources/metal.h resources/oil.h logic/game.h
	g++ -std=c++11 -I. -c ./robots/builder.cc -o ./robots/builder.cc.o
exceptions/badformatexception.cc.o: exceptions/badformatexception.cc \
 exceptions/badformatexception.h
	g++ -std=c++11 -I. -c ./exceptions/badformatexception.cc -o ./exceptions/badformatexception.cc.o
fields/field.cc.o: fields/field.cc logic/resourceset.h \
 resources/diamond.h resources/resource.h resources/gold.h \
 resources/metal.h resources/oil.h fields/field.h robots/robot.h \
 logic/game.h
	g++ -std=c++11 -I. -c ./fields/field.cc -o ./fields/field.cc.o
fields/fieldsfactory.cc.o: fields/fieldsfactory.cc fields/fieldsfactory.h \
 fields/field.h logic/resourceset.h resources/diamond.h \
 resources/resource.h resources/gold.h resources/metal.h resources/oil.h \
 fields/resourcefield.h robots/robot.h logic/game.h \
 robots/concreteminer.h robots/miner.h commands/test.h
	g++ -std=c++11 -I. -c ./fields/fieldsfactory.cc -o ./fields/fieldsfactory.cc.o
infXXXXXX/masterrobot.cc.o: infXXXXXX/masterrobot.cc actions/action.h \
 actions/mine.h actions/actioncapabler.h robots/miner.h robots/robot.h \
 logic/resourceset.h resources/diamond.h resources/resource.h \
 resources/gold.h resources/metal.h resources/oil.h logic/game.h \
 actions/move.h actions/anyrobotaction.h actions/create.h \
 robots/creator.h fields/resourcefield.h fields/field.h \
 robots/concreteminer.h infXXXXXX/masterrobot.h robots/builder.h \
 robots/transporter.h
	g++ -std=c++11 -I. -c ./infXXXXXX/masterrobot.cc -o ./infXXXXXX/masterrobot.cc.o
commands/loadworld.cc.o: commands/loadworld.cc commands/loadworld.h \
 logic/game.h exceptions/badformatexception.h
	g++ -std=c++11 -I. -c ./commands/loadworld.cc -o ./commands/loadworld.cc.o
commands/rungame.cc.o: commands/rungame.cc commands/rungame.h \
 logic/game.h
	g++ -std=c++11 -I. -c ./commands/rungame.cc -o ./commands/rungame.cc.o
commands/exit.cc.o: commands/exit.cc commands/exit.h logic/game.h
	g++ -std=c++11 -I. -c ./commands/exit.cc -o ./commands/exit.cc.o
commands/setplayer.cc.o: commands/setplayer.cc commands/setplayer.h \
 logic/game.h
	g++ -std=c++11 -I. -c ./commands/setplayer.cc -o ./commands/setplayer.cc.o
commands/test.cc.o: commands/test.cc logic/game.h commands/test.h
	g++ -std=c++11 -I. -c ./commands/test.cc -o ./commands/test.cc.o
commands/setgameout.cc.o: commands/setgameout.cc commands/setgameout.h \
 logic/game.h
	g++ -std=c++11 -I. -c ./commands/setgameout.cc -o ./commands/setgameout.cc.o
commands/liststudents.cc.o: commands/liststudents.cc \
 commands/liststudents.h logic/game.h
	g++ -std=c++11 -I. -c ./commands/liststudents.cc -o ./commands/liststudents.cc.o
logic/game.cc.o: logic/game.cc logic/game.h actions/actionfactory.h \
 robots/robot.h logic/resourceset.h resources/diamond.h \
 resources/resource.h resources/gold.h resources/metal.h resources/oil.h \
 actions/action.h actions/build.h actions/actioncapabler.h \
 robots/builder.h actions/create.h robots/creator.h actions/mine.h \
 robots/miner.h actions/move.h actions/anyrobotaction.h \
 actions/transfer.h fields/fieldsfactory.h fields/field.h \
 fields/resourcefield.h robots/concreteminer.h commands/test.h \
 exceptions/badformatexception.h
	g++ -std=c++11 -I. -c ./logic/game.cc -o ./logic/game.cc.o
logic/resourceset.cc.o: logic/resourceset.cc logic/resourceset.h \
 resources/diamond.h resources/resource.h resources/gold.h \
 resources/metal.h resources/oil.h
	g++ -std=c++11 -I. -c ./logic/resourceset.cc -o ./logic/resourceset.cc.o
actions/create.cc.o: actions/create.cc actions/create.h \
 actions/actioncapabler.h actions/action.h robots/creator.h \
 robots/robot.h logic/resourceset.h resources/diamond.h \
 resources/resource.h resources/gold.h resources/metal.h resources/oil.h \
 logic/game.h fields/field.h robots/warehouse.h
	g++ -std=c++11 -I. -c ./actions/create.cc -o ./actions/create.cc.o
actions/build.cc.o: actions/build.cc actions/build.h \
 actions/actioncapabler.h actions/action.h robots/builder.h \
 robots/robot.h logic/resourceset.h resources/diamond.h \
 resources/resource.h resources/gold.h resources/metal.h resources/oil.h \
 logic/game.h robots/warehouse.h fields/field.h
	g++ -std=c++11 -I. -c ./actions/build.cc -o ./actions/build.cc.o
actions/mine.cc.o: actions/mine.cc actions/mine.h \
 actions/actioncapabler.h actions/action.h robots/miner.h robots/robot.h \
 logic/resourceset.h resources/diamond.h resources/resource.h \
 resources/gold.h resources/metal.h resources/oil.h logic/game.h \
 fields/field.h robots/warehouse.h
	g++ -std=c++11 -I. -c ./actions/mine.cc -o ./actions/mine.cc.o
actions/move.cc.o: actions/move.cc actions/move.h \
 actions/anyrobotaction.h actions/action.h robots/robot.h \
 logic/resourceset.h resources/diamond.h resources/resource.h \
 resources/gold.h resources/metal.h resources/oil.h logic/game.h \
 robots/warehouse.h fields/field.h
	g++ -std=c++11 -I. -c ./actions/move.cc -o ./actions/move.cc.o
actions/anyrobotaction.cc.o: actions/anyrobotaction.cc \
 actions/anyrobotaction.h actions/action.h robots/robot.h \
 logic/resourceset.h resources/diamond.h resources/resource.h \
 resources/gold.h resources/metal.h resources/oil.h logic/game.h
	g++ -std=c++11 -I. -c ./actions/anyrobotaction.cc -o ./actions/anyrobotaction.cc.o
actions/transfer.cc.o: actions/transfer.cc actions/transfer.h \
 robots/robot.h logic/resourceset.h resources/diamond.h \
 resources/resource.h resources/gold.h resources/metal.h resources/oil.h \
 logic/game.h actions/anyrobotaction.h actions/action.h \
 robots/warehouse.h fields/field.h
	g++ -std=c++11 -I. -c ./actions/transfer.cc -o ./actions/transfer.cc.o
actions/action.cc.o: actions/action.cc actions/action.h robots/robot.h \
 logic/resourceset.h resources/diamond.h resources/resource.h \
 resources/gold.h resources/metal.h resources/oil.h logic/game.h
	g++ -std=c++11 -I. -c ./actions/action.cc -o ./actions/action.cc.o
infYYYYYY/masterrobot.cc.o: infYYYYYY/masterrobot.cc actions/action.h \
 actions/move.h actions/anyrobotaction.h logic/game.h \
 infYYYYYY/masterrobot.h robots/robot.h logic/resourceset.h \
 resources/diamond.h resources/resource.h resources/gold.h \
 resources/metal.h resources/oil.h robots/builder.h robots/creator.h \
 robots/concreteminer.h robots/miner.h robots/transporter.h
	g++ -std=c++11 -I. -c ./infYYYYYY/masterrobot.cc -o ./infYYYYYY/masterrobot.cc.o
main.cc.o: main.cc robots/robot.h logic/resourceset.h resources/diamond.h \
 resources/resource.h resources/gold.h resources/metal.h resources/oil.h \
 logic/game.h robots/builder.h robots/robot.h robots/concreteminer.h \
 robots/miner.h robots/creator.h robots/miner.h robots/transporter.h \
 logic/resourceset.h resources/diamond.h resources/gold.h \
 resources/metal.h resources/oil.h logic/game.h
	g++ -std=c++11 -I. -c ./main.cc -o ./main.cc.o
clean:
	rm -rf tournament ./robots/creator.cc.o ./robots/robot.cc.o ./robots/miner.cc.o ./robots/warehouse.cc.o ./robots/transporter.cc.o ./robots/builder.cc.o ./exceptions/badformatexception.cc.o ./fields/field.cc.o ./fields/fieldsfactory.cc.o ./infXXXXXX/masterrobot.cc.o ./commands/loadworld.cc.o ./commands/rungame.cc.o ./commands/exit.cc.o ./commands/setplayer.cc.o ./commands/test.cc.o ./commands/setgameout.cc.o ./commands/liststudents.cc.o ./logic/game.cc.o ./logic/resourceset.cc.o ./actions/create.cc.o ./actions/build.cc.o ./actions/mine.cc.o ./actions/move.cc.o ./actions/anyrobotaction.cc.o ./actions/transfer.cc.o ./actions/action.cc.o ./infYYYYYY/masterrobot.cc.o ./main.cc.o
