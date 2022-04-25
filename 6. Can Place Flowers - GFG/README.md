# 6. Can Place Flowers
## Easy 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in&nbsp;<strong>adjacent</strong>&nbsp;plots.</span></p>

<p><span style="font-size:18px">Given an integer array&nbsp;<strong><code>flowerbed</code></strong>&nbsp;containing&nbsp;<code>0</code>'s and&nbsp;<code>1</code>'s, where&nbsp;<code>0</code>&nbsp;means empty and&nbsp;<code>1</code>&nbsp;means not empty, and an integer&nbsp;<code>n</code>, return&nbsp;<em>if</em>&nbsp;<code>n</code>&nbsp;new flowers can be planted in the&nbsp;<code>flowerbed</code>&nbsp;without violating the no-adjacent-flowers rule.</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
N = 1
flowerbed[] = {1, 0, 0, 0, 1}
<strong>Output: </strong>1
<strong>Explanation:</strong> 
Place 1 flower at flowerbed[2].
flowerbed[] = {1, 0, 1, 0, 1}
</span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
N = 2
flowerbed[] = {1, 0, 0, 0, 1}
<strong>Output: </strong>0
<strong>Explanation:</strong> There is no possible way
of placing 2 non-adjacent flowers on 
the flowerbed.

</span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:&nbsp;&nbsp;</strong><br>
You don't need to read input or print anything. Your task is to complete the function <strong>canPlaceFlowers()</strong>&nbsp;which takes an array <strong>flowerbed</strong>&nbsp;and an integer&nbsp;<strong>N</strong>&nbsp;and returns an <strong>1</strong>&nbsp;if <strong>True</strong>, else returns <strong>0</strong>.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(N)<br>
<strong>Expected Auxiliary Space:</strong> O(1)</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 &lt;= N&lt;= 2*10<sup>4</sup><br>
0 &lt;= flowerbed[]&lt;= 1</span></p>
 <p></p>
            </div>