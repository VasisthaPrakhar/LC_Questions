# 7. Origin Passing
## Medium 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Given two coordinates <strong>(X1, Y1)</strong> and <strong>(X2, Y2)</strong> as an excel sheet number, for example - (13, AX),&nbsp;return true or false whether the line formed between the two points will pass through the origin.</span></p>

<p><span style="font-size:18px"><strong>Example 1:&nbsp;</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
X1 = 1
Y1 = "AA"
X2 = 2
Y2 = "AB"
<strong>Output:</strong>
0
<strong>Explanation</strong>: 
(X1, Y1) = (1, 27), (X2, Y2) = (2, 28)
Lines through these points does not
pass through origin.</span>
</pre>

<p><span style="font-size:18px"><strong>Example 2:&nbsp;</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong> 
X1 = 1
Y1 = "A"
X2 = 2
Y2 = "B" 
<strong>Output:</strong> 
1 
<strong>Explanation</strong>: 
(X1, Y1) = (1, 1), (X2, Y2) = (2, 2)
Lines through these points â€‹pass through
origin.
</span></pre>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read input or print anything. Your task is to complete the function <strong>pass_origin( )</strong>&nbsp;which takes <strong>X1</strong>, <strong>Y1</strong>, <strong>X2&nbsp;</strong>and <strong>Y2</strong>&nbsp;as input parameters and returns true or false. The driver will print 1 if the returned value is true or 0 otherwise. X1 and X2 are integers and Y1 and Y2 are strings.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(1)<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(1)</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ X1, X2&nbsp;≤ 10<sup>9</sup><br>
1 ≤ |Y1|, |Y2| ≤ 5<br>
Y1 and Y2 consists of uppercase english letters only.</span></p>
 <p></p>
            </div>