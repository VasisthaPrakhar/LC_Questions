# 9. Earliest Non-repeating Numbers
## Easy 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Given a stream of <strong>N</strong>&nbsp;integers in the form of an array <strong>A[ ]</strong>, print an integer if it is the earliest non-repeating occurance of itself followed by a blank space.</span></p>

<p><span style="font-size:18px"><strong>Example 1:&nbsp;</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
N = 5
parent[] = {1, 2, 4, 2, 3}
<strong>Output:</strong>
1 2 4 3 
<strong>Explanation</strong>: 
The fourth number is repeating.
</span></pre>

<p><span style="font-size:18px"><strong>Example 2:&nbsp;</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong> 
N = 3 
parent[] = {1, 2, 3} 
<strong>Output:</strong> 
1 2 3 
<strong>Explanation</strong>: 
No number is repeating
</span></pre>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
Your task is to complete the function <strong>non_repeating( )</strong>&nbsp;which takes <strong>N&nbsp;</strong>and <strong>A[ ]</strong>&nbsp;as input parameters and prints an integer according to the problem followed by a blank space. The main function will take care of ending line.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(N * Log(N))<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(N)</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N ≤ 2*10<sup>5</sup><br>
1 ≤ A[i] ≤ 10<sup>9</sup></span></p>
 <p></p>
            </div>