### Decisions Points

* Inventory management - use black on white background or white on black.  Preference is black on white but 180 bytes can be saved with the reverse.
* Dice animations - preference is to include this but it adds 558 bytes.
* Tile rotations - no preference and the decision will be dependent on the number of tiles that need rotating and how many rotations.  Removing the rotation code will also free up RAM - (1024 bytes of Progmem / 36 bytes of RAM).
* Sound library - preference is to have at least a theme tune and possibly other sound effects but the library alone is 800+ bytes with themes extra. The 1943 theme is approximately 250 bytes long.


### Metrics

* Tiles use 34 bytes of Progmem and 2 bytes of RAM
* Levels use approximately 75 / 100 bytes depending on the number of enemies and items in the level.


### Current Limitations

* Number of doors per level = 3
* Number of enemies per level = ~18~ ~14~ 15
* Number of items per level = ~18~ ~14~ 15

Note: These have been chosen to ensure the RAM is under 75% utilized.  Note the allocation can be redistributed if need be and increased if we remove the rotation code.


### To Do

- [X] Create a todo list.
- [ ] Revisit the 'defend' logic. 
- [ ] Move source files into subfolders.
- [ ] Restructure image files / minimise includes.
- [ ] Include enemy HP / AP / etc metrics.
- [X] Revisit move enemy logic to incorporate above metrics.
- [ ] Change map diagrams to use zero-based tile numbers.
- [X] Include logic for player dying.
- [X] Make rotation code optional.
- [X] Include AP, DF on inventory summary.
- [X] Change 'Attack' code to use player's AP as maximum random number.
- [X] Change 'Defend' mode to calculate a HP loss of random up to enemy's AP - random up to player's DF (must be zero or positive).
- [ ] Add logic to reset player stats when starting a second game.
- [ ] Fix enemy HP bar to handle values greater than 12 (need floating point values)


### Outstanding Questions

- [X] ~Are the HP / AP / etc metrics of an enemy fixed across all levels or are they level specific?~
	+ ~[Cyril] Nope, I think it should stay consistent - plus we can declare those values once and for all, and not per level.~ 
* ~Do you need to kill all enemies before proceeding to the next level?  I assume not.~
	+ ~[Cyril] Nope~
* Do you always get 1 DF point when progressing to the next level?  Is it fixed at 1 point or random?
	+ [Cyril] 1 point at random between AP, DF or HP was my original idea. I want to highlight that it's when you level up, though (just to clear the confusion of levelling up, versus entering a new maze level)
	+ [Simon] Oh, I might have confused myself. Levelling up is when you kill an enemy?
* ~There are three consumable slots in inventory.  You can collect multiple scrolls (magic).  Can you collect multiple keys and potions?~
	+ ~[Cyril] Up to 3 (they don't stalk) of anything in whatever order.~
	+ ~[Simon] Ah, that makes a lot of sense. So you can have any three items so maybe your inventory is a key and a potion and a second potion. I have coded it wrong then. At the moment, if you collect two potions it just puts them into the same slot.~
* ~Are there only three consumable inventory items?  If so, when do you ever have a 'No Slots Available' warning?~
	+ ~[Cyril] When you are trying to collect anything and your 3 slots are full~
* ~Is there any need to scroll the inventory selector through the Sword and Shield icons?  Why would you ever need to select them in the inventory?~
	+ ~[Cyril] Nope - I had the idea of designing various weapons and shields that would change the AP and DF stats of the player, but I don't want to make the game more complex than it is, and that would mean more GFXs. At this point, I think the level up system achieves the same.~
* Currently, you have to put an item found in the dungeon into inventory.  You can then use the item from within the inventory maintenance screen.  Should the player be able to consume a potion immediately?
* Is there a maximum HP for the player?  
* What are the starting HP, AP, DF for the player in level 1?
* Can someone please explain the 'LevelUp' logic to me?
* In the 'How to Play', the 'Defend Option' states that after defending the game will move automatically back to the PLAYER turn.  Is this correct?  Should it be ENEMY turn?
* In the 'How to Play', the 'Drink a Potion' states that after defending the game will move automatically back to the ENEMY turn.  Is this correct?  Should it be PLAYER turn?
* What is the level on the level up?