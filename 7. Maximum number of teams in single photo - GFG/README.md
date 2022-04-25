# 7. Maximum number of teams in single photo
## Easy 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Given N teams and each team has same number of members with their heights given. Now N teams have come together for a group photo. Now we have to arrange teams in rows such that:</span></p>

<p><span style="font-size:18px">1. One row will have members from one team only.</span></p>

<p><span style="font-size:18px">2. The height of a person at ith row should be greater than the height of the corresponding person at i-1th row so that all persons are visible in the photo.</span></p>

<p><span style="font-size:18px">3. Either entire team will get the photo clicked or if any one member of team is not visible then that entire team will forfeit the group photo.</span></p>

<p><span style="font-size:18px">We have to find the maximum no. of teams that can be clicked in a single photo.</span></p>

<p><strong><span style="font-size:18px">Example 1:</span></strong></p>

<pre><strong><span style="font-size:18px">Input: </span></strong><span style="font-size:18px">4 2 1 1 3
</span><strong><span style="font-size:18px">Output: </span></strong><span style="font-size:18px">4
</span><strong><span style="font-size:18px">Explanation: </span></strong><span style="font-size:18px">We can see that teams with 
height 4,2,1 and 3 can be arranged in 
consecutive rows to take a photo. So 4 
teams can be clicked in a single photo.</span></pre>

<p><strong><span style="font-size:18px">Example 2:</span></strong></p>

<pre><strong><span style="font-size:18px">Input: </span></strong><span style="font-size:18px">24 24 24 24 3
</span><strong><span style="font-size:18px">Output: </span></strong><span style="font-size:18px">2
</span><strong><span style="font-size:18px">Explanation: </span></strong><span style="font-size:18px">We can see that teams 
with height 24 and 3 can be arranged 
in consecutive rows to take a photo.
So 2 teams can be clicked in a single
photo.</span></pre>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>maximumNumberOfTeams()</strong>which takes teams as input parameter and returns an integer denoting the maximum number of teams that can be clicked in a single photo.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>O(N)<br>
<strong>Expected Auxiliary Space:</strong>O(N)</span></p>

<p><br>
<span style="font-size:18px"><strong>Constraints:</strong><br>
1 &lt;= N &lt;= 10<sup>5</sup><br>
1 &lt;= team[i]&lt;= 10<sup>5</sup></span></p>
 <p></p>
            </div>