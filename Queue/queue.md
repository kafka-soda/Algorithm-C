队列这种数据结构的数据也呈线性排列。虽然与栈有些相似，但队列中添加和删除数据的操作分别是在两端进行的。就和“队列”这个名字一样，把它想象成排成一队的人更容易理解。在队列中，处理总是从第一名开始往后进行，而新来的人只能排在队尾。

![](https://github.com/kafka-soda/Algorithm-C/blob/master/Png-Res/queue01.PNG)
这就是队列的概念图。现在队列中只有数据 Blue。

![](https://github.com/kafka-soda/Algorithm-C/blob/master/Png-Res/queue02.PNG)
然后，队列中添加了数据 Green。

![](https://github.com/kafka-soda/Algorithm-C/blob/master/Png-Res/queue03.PNG)
紧接着，数据 Red 也入队了。

![](https://github.com/kafka-soda/Algorithm-C/blob/master/Png-Res/queue04.PNG)
从队列中取出（删除）数据时，是从最下面，也就是最早入队的数据开始的。这里取出的是 Blue。

![](https://github.com/kafka-soda/Algorithm-C/blob/master/Png-Res/queue05.PNG)
如果再进行一次出队操作，取出的就是 Green 了。

解说
像队列这种最先进去的数据最先被取来，即“先进先出”的结构，我们称为 First In First Out，简称 FIFO。
与栈类似，队列中可以操作数据的位置也有一定的限制。在栈中，数据的添加和删除都在同一端进行，而在队列中则分别是在两端进行的。队列也不能直接访问位于中间的数据，必须通过出队操作将目标数据变成首位后才能访问。应用示例
“先来的数据先处理”是一种很常见的思路，所以队列的应用范围非常广泛。比如 4-2 节中将要讲解的广度优先搜索算法，通常就会从搜索候补中选择最早的数据作为下一个顶点。此时，在候补顶点的管理上就可以使用队列。
