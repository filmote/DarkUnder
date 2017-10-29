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


### Known Bugs

- [ ] Tried the new build: there is a bug: when you die and restart, your HP doesn’t get reset :slight_smile: Right now, the game is rather brutal!
- [ ] The scroll image is reversed (black on white instead of white on black)
- [ ] The small enemy images are not always rendered.


### Outstanding Questions

- [X] ~Are the HP / AP / etc metrics of an enemy fixed across all levels or are they level specific?~
	+ ~[Cyril] Nope, I think it should stay consistent - plus we can declare those values once and for all, and not per level.~ 
- [X] ~Do you need to kill all enemies before proceeding to the next level?  I assume not.~
	+ ~[Cyril] Nope~
- [X] Do you always get 1 DF point when progressing to the next level?  Is it fixed at 1 point or random?
	+ [Cyril] 1 point at random between AP, DF or HP was my original idea. I want to highlight that it's when you level up, though (just to clear the confusion of levelling up, versus entering a new maze level)
	+ [Simon] Oh, I might have confused myself. Levelling up is when you kill an enemy?
- [X] ~There are three consumable slots in inventory.  You can collect multiple scrolls (magic).  Can you collect multiple keys and potions?~
	+ ~[Cyril] Up to 3 (they don't stalk) of anything in whatever order.~
	+ ~[Simon] Ah, that makes a lot of sense. So you can have any three items so maybe your inventory is a key and a potion and a second potion. I have coded it wrong then. At the moment, if you collect two potions it just puts them into the same slot.~
- [X] ~Are there only three consumable inventory items?  If so, when do you ever have a 'No Slots Available' warning?~
	+ ~[Cyril] When you are trying to collect anything and your 3 slots are full~
- [X] ~Is there any need to scroll the inventory selector through the Sword and Shield icons?  Why would you ever need to select them in the inventory?~
	+ ~[Cyril] Nope - I had the idea of designing various weapons and shields that would change the AP and DF stats of the player, but I don't want to make the game more complex than it is, and that would mean more GFXs. At this point, I think the level up system achieves the same.~
* [X] ~Currently, you have to put an item found in the dungeon into inventory.  You can then use the item from within the inventory maintenance screen.  Should the player be able to consume a potion immediately?~
	+ ~[Simon] I have changed the code to allow the player to drop an item (oner per cell / space).~
* [ ] Is there a maximum HP for the player?  
	+ [Cyril] It depends what’s simpler for you: traditionally there is, but I think for our game, we could say no without impacting the gameplay.
	+ [Pharap] Yes. 255 of course :P. Seriously though, we don’t want any overflow bugs. Unless death by potion overuse is a mechanic we want to consider? Note that if there is no cap then adding HP on level up is pointless, so levelling up would have to only affect attack and defence.
	+ [Simon] Additionally, I need to add a space padding for a three digit number.  I would like to cap it at 99.
* [X] ~What are the starting HP, AP, DF for the player in level 1?~
    + ~[Cyril] I would put the HP at 10, the AP at 2 and DF at 1. We may need to revisit that after playtesting.~
	+ ~[Simon] I have set these values and we can reassess.~
* [X] ~In the 'How to Play', the 'Defend Option' states that after defending the game will move automatically back to the PLAYER turn.  Is this correct?  Should it be ENEMY turn?!
    + ~[Cyril] Nope: when you choose defend, next, it shows you the screen with you holding your shield. on that screen, you get attacked by the enemy but have a shot at mitigating the damage depending on your DF and you deal 1 flat damage. Since you already got attacked, then it goes back to your initiative screen.~
	+ ~[Simon] OK, I have changed the logic to do that.~
* [ ] In the 'How to Play', the 'Drink a Potion' states that after defending the game will move automatically back to the ENEMY turn.  Is this correct?  Should it be PLAYER turn?
    + [Cyril] Depends: if we get to the enemy screen, that means that the player skips a turn by drinking the potion, and get attacked twice. That makes drinking a potion a bit of a gamble (depending on how much damage you received before drinking, and after drinking) and the game more difficult. If we get back to the player screen, that means there is no downside drinking a potion and it makes the game easier. It really depends what we want to do.
	+ [Pharap] That’s a tough one. Though if we’re sticking with 3 items slots the most a player can ever recover in a battle is 15 HP so it won’t be that much of an advantage against a tougher enemy, unless we introduce different sized potions, or make HP recovery relative to player level.
* [ ] What is the level on the level up?
    + [Cyril] Not sure I understand the question? The level is shown under the cup, above the random stat gain.
	+ [Simon] Yes but what is it? Its not the dungeon level you are playing, so what does the ‘level’ represent?

