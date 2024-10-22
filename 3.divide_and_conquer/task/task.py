import matplotlib.pyplot as plt
import numpy as np
import random

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

# 计算两点之间的欧几里得距离
def euclidean_distance(p1, p2):
    return np.sqrt((p2.x - p1.x) ** 2 + (p2.y - p1.y) ** 2)

# 暴力法计算最近点对
def brute_force(points):
    min_distance = float('inf')
    closest_pair1 = (None, None)
    
    for i in range(len(points)):
        for j in range(i + 1, len(points)):
            distance = euclidean_distance(points[i], points[j])
            if distance < min_distance:
                min_distance = distance
                closest_pair1 = (points[i], points[j])
    
    return closest_pair1, min_distance

# 绘制当前点集和最近点对
def plot_points(points, closest_pair, depth):
    plt.figure(figsize=(8, 6))
    
    for p in points:
        plt.scatter(p.x, p.y, color='blue')
    
    if closest_pair[0] is not None and closest_pair[1] is not None:
        plt.scatter(closest_pair[0].x, closest_pair[0].y, color='red', s=100, label='Closest Point 1')
        plt.scatter(closest_pair[1].x, closest_pair[1].y, color='green', s=100, label='Closest Point 2')
        plt.plot([closest_pair[0].x, closest_pair[1].x], [closest_pair[0].y, closest_pair[1].y], color='black', linestyle='--')
    
    plt.title(f'Recursion Depth {depth}')
    plt.xlabel('X coordinate')
    plt.ylabel('Y coordinate')
    plt.xlim(0, 100)
    plt.ylim(0, 100)
    plt.legend()
    plt.grid(True)
    plt.show()

def plot_points1(points, closest_pair, depth):
    plt.figure(figsize=(8, 6))
    
    for p in points:
        plt.scatter(p.x, p.y, color='blue')
    
    
    
    plt.title("Random set of points")
    plt.xlabel('X coordinate')
    plt.ylabel('Y coordinate')
    plt.xlim(0, 100)
    plt.ylim(0, 100)
    plt.legend()
    plt.grid(True)
    plt.show()

# 分治法寻找最近点对
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

# 生成随机点
def generate_random_points(n):
    return [Point(random.uniform(0, 100), random.uniform(0, 100)) for _ in range(n)]

# 主程序
def main():
    n = 20  # 点的数量
    points = generate_random_points(n)
    plot_points1(points, (1,1), 0)
    
    if len(points) < 2:
        print("Not enough points to find a closest pair.")
        return

    # 将点按 x 坐标排序
    points_x = sorted(points, key=lambda p: p.x)
    points_y = sorted(points, key=lambda p: p.y)
    
    closest_pair_result, min_distance = closest_pair(points_x, points_y)
    
    # 确保最近点对不为 None
    if closest_pair_result[0] is not None and closest_pair_result[1] is not None:
        print(f"The closest pair is: ({closest_pair_result[0].x}, {closest_pair_result[0].y}) and ({closest_pair_result[1].x}, {closest_pair_result[1].y}) with a distance of {min_distance:.2f}")
    else:
        print("No closest pair found.")

if __name__ == "__main__":
    main()
