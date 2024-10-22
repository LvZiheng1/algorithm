分治算法的核心就是：**分解子问题+求解子问题+把子问题合并**

* 分解子问题：不要想着完美的分解成两个子问题，你还要想着还有合并这个步骤，它们两个一起在宏观上想才能想到好办法。比如求解点集的最短子对，你想着分解成左右两个部分的子问题，分别求它们的最短子对，然后求出来了又有什么用呢？最短子对完全可以不在你的左边部分或右边部分，它可能跨过左右两部分啊！！？这时候就轮到合并出场了，它负责解决这个问题。

* 求解子问题：将子问题分解的足够小的时候，就可以用简单的办法解决。比如最短子对，就是分解到规模足够小时直接暴力求解。
* 合并：合并是很重要也是最困难的一步，它关系着怎么将求解好的子问题进行有效的合并。比如二路归并的合并就专门写了个合并的函数，把两个有序数组合并为一个有序数组。比如最短子对的合并就是以mid_point为主，做一个strip区，这个区内的点暴力求解出最短子对。你仔细琢磨会发现它们的合并算法都设计的很巧妙，不会遗漏任何情况。其实合并就是把两个或多个子问题合并起来成为一个更高一层的子问题。合并能不能合其实还取决于你的分解怎么分，你分的不好就合并不成功的，比如最短点对，你不按x坐标排序然后找个mid_point对半分解问题的话，其实根本就不会出现它巧妙的合并算法。

tips:

* 分解子问题和合并子问题是紧密相连的，而求解子问题则可以说是相对脱离的，你只需要能够把分解的足够小的问题求解出来（这也是递归出口），并且返回需要的值（比如最短点对就是求解子问题时返回子对和最小距离）就行了。
* 在分解子问题时要有整体思想，也就是说你要事先就认定你的子问题已经求解出来了，再去想其它的事，再去想怎么合并。具体怎么求解出来的，你先不用想，当你把合并解决了，自然就知道了。比如最短子对，我分成了左右两部分，我认定两个子问题都已经求解出来了，我解出来了左右两部分分别的最短子对，接下来怎么办吧！！！怎么才能合并两部分的解来得到我整体的解。这是整个解决问题时的整体宏观思想。



我接下来会把我做过的题都贴出来，让你理解分治的思想！你就往这三个核心步骤上拆分就行。

*********



1. ![image-20241022183736867]('.\pic\1.png')
   ```python
   ####把核心的分治代码贴于此，认真体会一下
   
   def closest_pair(points_x, points_y, depth=0):
       # 如果点数量小于等于3，使用暴力法计算最近点对
       if len(points_x) <= 3:
           return brute_force(points_x)
       
       # 找到中间位置
       mid = len(points_x) // 2
       mid_point = points_x[mid]
       
       left_points_x = points_x[:mid]
       right_points_x = points_x[mid:]
       
       left_points_y = list(filter(lambda p: p.x <= mid_point.x, points_y))
       right_points_y = list(filter(lambda p: p.x > mid_point.x, points_y))
       
       
       
       # 递归计算左右两边的最近点对
       (p1, p2), d1 = closest_pair(left_points_x, left_points_y, depth + 1)
       (p3, p4), d2 = closest_pair(right_points_x, right_points_y, depth + 1)
       
       
       
       # 取左右两边最小距离的最近点对
       if d1 < d2:
           closest_pair1 = (p1, p2)
           min_distance = d1
       else:
           closest_pair1 = (p3, p4)
           min_distance = d2
       
       # 绘制当前递归层次下的点集和最近点对
       plot_points(points_x, closest_pair1, depth)
       
       # 构造中间带宽区域的点
       strip = [p for p in points_y if abs(p.x - mid_point.x) < min_distance]
       
       # 检查中间带宽区域的最近点对
       for i in range(len(strip)):
           for j in range(i + 1, len(strip)):
               if (strip[j].y - strip[i].y) < min_distance:
                   distance = euclidean_distance(strip[i], strip[j])
                   if distance < min_distance:
                       min_distance = distance
                       closest_pair1 = (strip[i], strip[j])
                       
       return closest_pair1, min_distance
   ```
   
   
   
   



