

HW12

Oh wow, this assignment was tough, but I had a lot of fun! It felt really satisfying when everything finally worked.

I started by doing the part I was most comfortable with: drawing the circuit and connecting everything on the breadboard. However, I struggled to get the photoresistor to work, so I replaced it with another button instead.

Even with the button, I ran into issues. After some research, I learned there are different ways to connect a button. I taught myself about pull-up and pull-down resistors, adjusted the code, removed the resistors, and eventually got the button to work on its own.

The hardest part was figuring out the logic for the code. At first, I didn’t think to use numbers to track the password’s steps or progress. This had me stuck for a long time. Once I figured that out, I had to deal with another problem: how to record just the press of a button without also capturing the release. It was tricky because both pressing and releasing a button change its state. I also needed to make sure each press only added a single “0” instead of spamming the output with zeros.

Here’s the key part of my code for handling the button:

if (button1State != s1) { // Check if the button's state has changed
  button1State = s1; // Update the button's state
  if (s1 == 0) { // If the button is pressed (not released)
    if (passwordProgress == 0) {
      passwordProgress += 1; // If nothing has been done yet, increase the progress by 1
    } else {
      passwordProgress = 0; // Otherwise, reset the progress to 0
    }
  }
}

The rest was easier. The logic is simple: every time you do the correct action when the passwordProgress matches the expected value, it adds 1. If something is wrong, the progress resets to 0. Once passwordProgress reaches 5 (meaning all steps are correct), the green light turns on.

<img src="HW12 circuit.jpg" />

