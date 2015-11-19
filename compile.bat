cls

@cl /nologo /Zi /GR- /EHs /MDd /c src/Character/Character.cc -I ../../../ESAT_rev109/include
@cl /nologo /Zi /GR- /EHs /MDd /c src/Character/Ally.cc -I ../../../ESAT_rev109/include
@cl /nologo /Zi /GR- /EHs /MDd /c src/Character/Foe.cc -I ../../../ESAT_rev109/include
@cl /nologo /Zi /GR- /EHs /MDd /c src/Character/Friend.cc -I ../../../ESAT_rev109/include
@cl /nologo /Zi /GR- /EHs /MDd /c src/Character/Job.cc -I ../../../ESAT_rev109/include
@cl /nologo /Zi /GR- /EHs /MDd /c src/Character/Race.cc -I ../../../ESAT_rev109/include
@cl /nologo /Zi /GR- /EHs /MDd /c src/Character/Dwarf.cc -I ../../../ESAT_rev109/include
@cl /nologo /Zi /GR- /EHs /MDd /c src/Character/Elf.cc -I ../../../ESAT_rev109/include
@cl /nologo /Zi /GR- /EHs /MDd /c src/Character/Human.cc -I ../../../ESAT_rev109/include
@cl /nologo /Zi /GR- /EHs /MDd /c src/Character/Orc.cc -I ../../../ESAT_rev109/include
@cl /nologo /Zi /GR- /EHs /MDd /c src/Character/Boss.cc -I ../../../ESAT_rev109/include
@cl /nologo /Zi /GR- /EHs /MDd /c src/Character/Hunter.cc -I ../../../ESAT_rev109/include
@cl /nologo /Zi /GR- /EHs /MDd /c src/Character/Warrior.cc -I ../../../ESAT_rev109/include
@cl /nologo /Zi /GR- /EHs /MDd /c src/Character/Wizard.cc -I ../../../ESAT_rev109/include


@cl /nologo /Zi /GR- /EHs /MDd /c src/Item/Item.cc -I ../../../ESAT_rev109/include
@cl /nologo /Zi /GR- /EHs /MDd /c src/Item/Inventory.cc -I ../../../ESAT_rev109/include
@cl /nologo /Zi /GR- /EHs /MDd /c src/Item/Armor.cc -I ../../../ESAT_rev109/include
@cl /nologo /Zi /GR- /EHs /MDd /c src/Item/Weapon.cc -I ../../../ESAT_rev109/include

@cl /nologo /Zi /GR- /EHs /MDd /c src/Screen/Screen.cc -I ../../../ESAT_rev109/include
@cl /nologo /Zi /GR- /EHs /MDd /c src/Screen/Intro.cc -I ../../../ESAT_rev109/include
@cl /nologo /Zi /GR- /EHs /MDd /c src/Screen/MainMenu.cc -I ../../../ESAT_rev109/include
@cl /nologo /Zi /GR- /EHs /MDd /c src/Screen/NewGame.cc -I ../../../ESAT_rev109/include
@cl /nologo /Zi /GR- /EHs /MDd /c src/Screen/OptionsMenu.cc -I ../../../ESAT_rev109/include
@cl /nologo /Zi /GR- /EHs /MDd /c src/Screen/Game.cc -I ../../../ESAT_rev109/include

@cl /nologo /Zi /GR- /EHs /MDd /c src/Main/Animation.cc -I ../../../ESAT_rev109/include
@cl /nologo /Zi /GR- /EHs /MDd /c src/Main/Manager.cc -I ../../../ESAT_rev109/include
@cl /nologo /Zi /GR- /EHs /MDd /c src/Main/Map.cc -I ../../../ESAT_rev109/include
@cl /nologo /Zi /GR- /EHs /MDd /c src/Main/Grid.cc -I ../../../ESAT_rev109/include
@cl /nologo /Zi /GR- /EHs /MDd /c src/Main/main.cc -I ../../../ESAT_rev109/include


@cl /nologo /Zi /GR- /EHs /MDd /Fe:TheBattleForPass.exe Character.obj Ally.obj Foe.obj Friend.obj Job.obj Race.obj Dwarf.obj Elf.obj Human.obj Orc.obj Boss.obj Hunter.obj Warrior.obj Wizard.obj Item.obj Inventory.obj Armor.obj Weapon.obj Screen.obj Intro.obj MainMenu.obj NewGame.obj OptionsMenu.obj Animation.obj Manager.obj Map.obj Grid.obj Game.obj main.obj ..\..\..\ESAT_rev109\bin\ESAT_d.lib opengl32.lib user32.lib gdi32.lib shell32.lib