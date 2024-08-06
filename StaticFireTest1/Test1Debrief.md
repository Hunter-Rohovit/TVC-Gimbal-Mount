Overall a successful first test. TVC mount stayed vertical throughout the duration of the test. Successful readings from load cells and writing data to SD cards. Comparing the test data to the manufacture's data showed a similar shape of a graph, with peak thrust around 0.2 seconds after ignition and relatively constant thrust for 1.6 seconds. The total impulse (8.76 N-s) was significantly lower than theoretical yield (10 N-s) likely due to incorrect calibration factors (need to recalibrate the load cells again to verify factors).

Looking at the scatterplot which maps out the center of force (akin to center of except with thrust instead of mass) for every data point taken by the loadcells, an apparent trend emerges. First, the TVC mount is relatively stable in the Y-direction. The Y-axis is controlled by the upper (or inner) servo directly connected to the motor holder. It was apparent when completing motion tests that this servo had significantly more control over its position compared to its counterpart servo. The range for the CF's Y position was 0.6213cm, compared to the range for the CF's X position which was 2.0751cm. Will keep this in mind for future versions of the TVC mount. However, this will not be changed for the next test.  

Additionally, the loadcells currently have a data logging rate of 10hz. After looking at the specifications of HX711 module, I inquired that it is possible to increase this rate to 80hz. While 10hz provides data to graph the thrust vs. time, we only obtain 20 total data points over the duration of the test. If we change this to 80hz, we can obtain 160 data points, providing a more accurate representation of the test. This will be changed for the next test. 

Turns out I can't ignore the ejection charge. Explosion at the end of the video was due to the ejection charge which sent the engine flying up into the air. I considered removing the ejection charge from the rocket engine, but due to safety concerns I will opt for a different option. Buying C6-0 engines is a difficult task as Estes produces very few of them. The other option which I will implement in Static Fire Test 2 is giving the rocket engine holder two side vents. The side vents at the bottom of the holder will allow pressure from the ejection charge to escape out the sides and shouldn't result in an airborne rocket engine. 

While writing this debrief initially, there didn't appear to be any significant damage to the TVC mount after testing. After further inspection it became clear that the outer loop of the TVC mount broke at its hinge. Before the test this was a major area of concern as the hinge wasn't solidly connected to the TVC mount. To correct this issue, the areas around the hinge will be widened to give it more support. Additionally, the PLA filament that was used for V1 will be replaced with PETG filament (a stronger variant of plastic) for V2.
<br>
Changes for test 2:<br>
-10hz to 80hz data log rate <br>
-side vents in engine holder<br>
-Recalibrated load cells<br>
-PLA to PETG<br>
-Widened hinges<br>
-Added Electronics Shield (see Ejection Vent Test)<br>
-Test Engine Gimbal (Max Corners)<br>
