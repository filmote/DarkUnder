## Decisions Points

* Inventory management – use black on white background or white on black.  Preference is black on white but 180 bytes can be saved with the reverse.
* Dice animations – preference is to include this but it adds 558 bytes.
* Tile rotations – no preference and the decision will be dependent on the number of tiles that need rotating and how many rotations.  Removing the rotation code will also free up RAM.
* Sound library – preference is to have at least a theme tune and possibly other sound effects but the library alone is 800+ bytes with themes extra. The 1943 theme is approximately 250 bytes long.

## Metrics

* Tiles use 34 bytes of Progmem and 2 bytes of RAM
* Levels use approximately 75 – 100 bytes depending on the number of enemies and items in the level.

## Current Limitations

* Number of doors per level = 3
* Number of enemies per level = 18
* Number of items per level = 18

Note: These have been chosen to ensure the RAM is under 75% utilized.  Note the allocation can be redistributed if need be and increased if we remove the rotation code.

## To Do

- [X] Create a todo list.
- [ ] Revisit the ‘defend’ logic. 
- [ ] Move source files into subfolders.
- [ ] Restructure image files / minimise includes.
- [ ] Include enemy HP / AP / etc metrics
- [ ] Revisit ‘attack’ logic to incorporate above metrics


## Outstanding Questions

* ~Are the HP / AP / etc metrics of an enemy fixed across all levels or are they level specific?~
	+ ~[Cyril] Nope, I think it should stay consistent - plus we can declare those values once and for all, and not per level.~ 
* ~Do you need to kill all enemies before proceeding to the next level?  I assume not.~
	+ ~[Cyril] Nope~
* Do you always get 1 DF point when progressing to the next level?  Is it fixed at 1 point or random?
	+ [Cyril] 1 point at random between AP, DF or HP was my original idea. I want to highlight that it’s when you level up, though (just to clear the confusion of levelling up, versus entering a new maze level)
	+ [Simon] Oh, I might have confused myself. Levelling up is when you kill an enemy?
* ~There are three consumable slots in inventory.  You can collect multiple scrolls (magic).  Can you collect multiple keys and potions?~
	+ ~[Cyril] Up to 3 (they don’t stalk) of anything in whatever order.~
	+ ~[Simon] Ah, that makes a lot of sense. So you can have any three items so maybe your inventory is a key and a potion and a second potion.~
I have coded it wrong then. At the moment, if you collect two potions it just puts them into the same slot.
* Are there only three consumable inventory items?  If so, when do you ever have a 'No Slots Available' warning?
	+ [Cyril] When you are trying to collect anything and your 3 slots are full
* Is there any need to scroll the inventory selector through the Sword and Shield icons?  Why would you ever need to select them in the inventory?
	+ [Cyril] Nope - I had the idea of designing various weapons and shields that would change the AP and DF stats of the player, but I don’t want to make the game more complex than it is, and that would mean more GFXs. At this point, I think the level up system achieves the same.
	
