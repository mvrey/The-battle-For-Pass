cls


REM Third Part Libraries
@cl /nologo /Zi /GR- /EHs /MDd /c lib/TMXparser/tinyxml2.cpp
@cl /nologo /Zi /GR- /EHs /MDd /c lib/TMXparser/miniz.cpp
@cl /nologo /Zi /GR- /EHs /MDd /c lib/TMXparser/TmxUtil.cpp
@cl /nologo /Zi /GR- /EHs /MDd /c lib/TMXparser/TmxTileset.cpp
@cl /nologo /Zi /GR- /EHs /MDd /c lib/TMXparser/TmxTileOffset.cpp
@cl /nologo /Zi /GR- /EHs /MDd /c lib/TMXparser/TmxTileLayer.cpp
@cl /nologo /Zi /GR- /EHs /MDd /c lib/TMXparser/TmxTile.cpp
@cl /nologo /Zi /GR- /EHs /MDd /c lib/TMXparser/TmxTerrainArray.cpp
@cl /nologo /Zi /GR- /EHs /MDd /c lib/TMXparser/TmxTerrain.cpp
@cl /nologo /Zi /GR- /EHs /MDd /c lib/TMXparser/TmxPropertySet.cpp
@cl /nologo /Zi /GR- /EHs /MDd /c lib/TMXparser/TmxPolyline.cpp
@cl /nologo /Zi /GR- /EHs /MDd /c lib/TMXparser/TmxPolygon.cpp
@cl /nologo /Zi /GR- /EHs /MDd /c lib/TMXparser/TmxObjectGroup.cpp
@cl /nologo /Zi /GR- /EHs /MDd /c lib/TMXparser/TmxObject.cpp
@cl /nologo /Zi /GR- /EHs /MDd /c lib/TMXparser/TmxMap.cpp
@cl /nologo /Zi /GR- /EHs /MDd /c lib/TMXparser/TmxLayer.cpp
@cl /nologo /Zi /GR- /EHs /MDd /c lib/TMXparser/TmxImageLayer.cpp
@cl /nologo /Zi /GR- /EHs /MDd /c lib/TMXparser/TmxImage.cpp
@cl /nologo /Zi /GR- /EHs /MDd /c lib/TMXparser/TmxEllipse.cpp


REM My Source Code
@cl /nologo /Zi /GR- /EHs /MDd /c src/Character/Ally.cc -I ../../../ESAT_rev109/include
@cl /nologo /Zi /GR- /EHs /MDd /c src/Character/Boss.cc -I ../../../ESAT_rev109/include
@cl /nologo /Zi /GR- /EHs /MDd /c src/Character/Brown_Asp.cc -I ../../../ESAT_rev109/include
@cl /nologo /Zi /GR- /EHs /MDd /c src/Character/Character.cc -I ../../../ESAT_rev109/include
@cl /nologo /Zi /GR- /EHs /MDd /c src/Character/Dwarf.cc -I ../../../ESAT_rev109/include
@cl /nologo /Zi /GR- /EHs /MDd /c src/Character/Elf.cc -I ../../../ESAT_rev109/include
@cl /nologo /Zi /GR- /EHs /MDd /c src/Character/Foe.cc -I ../../../ESAT_rev109/include
@cl /nologo /Zi /GR- /EHs /MDd /c src/Character/Friend.cc -I ../../../ESAT_rev109/include
@cl /nologo /Zi /GR- /EHs /MDd /c src/Character/Human.cc -I ../../../ESAT_rev109/include
@cl /nologo /Zi /GR- /EHs /MDd /c src/Character/Hunter.cc -I ../../../ESAT_rev109/include
@cl /nologo /Zi /GR- /EHs /MDd /c src/Character/Job.cc -I ../../../ESAT_rev109/include
@cl /nologo /Zi /GR- /EHs /MDd /c src/Character/Orc.cc -I ../../../ESAT_rev109/include
@cl /nologo /Zi /GR- /EHs /MDd /c src/Character/Race.cc -I ../../../ESAT_rev109/include
@cl /nologo /Zi /GR- /EHs /MDd /c src/Character/Warrior.cc -I ../../../ESAT_rev109/include
@cl /nologo /Zi /GR- /EHs /MDd /c src/Character/Wizard.cc -I ../../../ESAT_rev109/include

@cl /nologo /Zi /GR- /EHs /MDd /c src/Item/Armor.cc -I ../../../ESAT_rev109/include
@cl /nologo /Zi /GR- /EHs /MDd /c src/Item/Inventory.cc -I ../../../ESAT_rev109/include
@cl /nologo /Zi /GR- /EHs /MDd /c src/Item/Item.cc -I ../../../ESAT_rev109/include
@cl /nologo /Zi /GR- /EHs /MDd /c src/Item/Weapon.cc -I ../../../ESAT_rev109/include

@cl /nologo /Zi /GR- /EHs /MDd /c src/Screen/Battle.cc -I ../../../ESAT_rev109/include
@cl /nologo /Zi /GR- /EHs /MDd /c src/Screen/Game.cc -I ../../../ESAT_rev109/include
@cl /nologo /Zi /GR- /EHs /MDd /c src/Screen/Intro.cc -I ../../../ESAT_rev109/include
@cl /nologo /Zi /GR- /EHs /MDd /c src/Screen/MainMenu.cc -I ../../../ESAT_rev109/include
@cl /nologo /Zi /GR- /EHs /MDd /c src/Screen/NewGame.cc -I ../../../ESAT_rev109/include
@cl /nologo /Zi /GR- /EHs /MDd /c src/Screen/OptionsMenu.cc -I ../../../ESAT_rev109/include
@cl /nologo /Zi /GR- /EHs /MDd /c src/Screen/GameOver.cc -I ../../../ESAT_rev109/include
@cl /nologo /Zi /GR- /EHs /MDd /c src/Screen/Screen.cc -I ../../../ESAT_rev109/include

@cl /nologo /Zi /GR- /EHs /MDd /c src/Main/Animation.cc -I ../../../ESAT_rev109/include
@cl /nologo /Zi /GR- /EHs /MDd /c src/Main/Grid.cc -I ../../../ESAT_rev109/include
@cl /nologo /Zi /GR- /EHs /MDd /c src/Main/Manager.cc -I ../../../ESAT_rev109/include
@cl /nologo /Zi /GR- /EHs /MDd /c src/Main/Map.cc -I ../../../ESAT_rev109/include
@cl /nologo /Zi /GR- /EHs /MDd /c src/Main/Misc.cc -I ../../../ESAT_rev109/include
@cl /nologo /Zi /GR- /EHs /MDd /c src/Main/main.cc -I ../../../ESAT_rev109/include


@cl /nologo /Zi /GR- /EHs /MDd /Fe:TheBattleForPass.exe miniz.obj TmxUtil.obj TmxTileset.obj TmxTileOffset.obj TmxTileLayer.obj TmxTile.obj TmxTerrainArray.obj TmxTerrain.obj TmxPropertySet.obj TmxPolyline.obj TmxPolygon.obj TmxObjectGroup.obj TmxObject.obj TmxMap.obj TmxLayer.obj TmxImageLayer.obj TmxImage.obj TmxEllipse.obj Ally.obj Boss.obj Brown_Asp.obj Character.obj Dwarf.obj Elf.obj Foe.obj Friend.obj Human.obj Hunter.obj Job.obj Orc.obj Race.obj Warrior.obj Wizard.obj Armor.obj Inventory.obj Item.obj Weapon.obj Battle.obj Game.obj Intro.obj MainMenu.obj NewGame.obj OptionsMenu.obj GameOver.obj Screen.obj Animation.obj Grid.obj Manager.obj Map.obj Misc.obj main.obj ..\..\..\ESAT_rev109\bin\ESAT_d.lib opengl32.lib user32.lib gdi32.lib shell32.lib