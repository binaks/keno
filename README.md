# Keno
Keno is a lottery-like game. 
The player places a bet by choosing up to 15 numbers between 1 and 80, and then 20 numbers in that range are randomly generated.
The player is paid based on how many of the chosen numbers were generated.

## How to play

Run
```
make
```

Then add a bet file in /data/, in which:
* your initial credit goes on the first line
* the number of rounds you want to play goes on the second line
* the numbers you choose go on the third line (separated by spaces)

If you need help, there's an example bet file in /data/.

To start playing, run 
```
./keno /data/(NAME-OF-BET-FILE)
```
replacing (NAME-OF-BET-FILE) with the name of the file you created.

## Made by
* Bianca Rodrigues Cesarino
* Gustavo Batista de Araújo Gorgônio
