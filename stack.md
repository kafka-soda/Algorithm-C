# Algorithm-C

Stack-栈
栈是一种数据呈线性排列的数据结构，不过在这种结构中，我们只能访问最新添加的数据。栈就像是一摞书，拿到新书时我们会把它放在书堆的最上面，取书时也只能从最上面的新书开始取。

![](https://github.com/kafka-soda/Algorithm-C/blob/master/stack01.PNG)
这就是栈的概念图。现在存储在栈中的只有数据 Blue。

https://github.com/kafka-soda/Algorithm-C/blob/master/stack02.PNG
然后，栈中添加了数据 Green。

https://github.com/kafka-soda/Algorithm-C/blob/master/stack03.PNG
接下来，数据 Red 入栈。

https://github.com/kafka-soda/Algorithm-C/blob/master/stack04.PNG
从栈中取出数据时，是从最上面，也就是最新的数据开始取出的。这里取出的是 Red。

https://github.com/kafka-soda/Algorithm-C/blob/master/stack05.PNG
如果再进行一次出栈操作，取出的就是 Green 了。

解说
像栈这种最后添加的数据最先被取出，即“后进先出”的结构，我们称为 Last In First Out，简称 LIFO。
与链表和数组一样，栈的数据也是线性排列，但在栈中，添加和删除数据的操作只能在一端进行，访问数据也只能访问到顶端的数据。想要访问中间的数据时，就必须通过出栈操作将目标数据移到栈顶才行。

另外深度优先搜索算法，通常会选择最新的数据作为候补顶点。在候补顶点的管理上就可以使用栈。


