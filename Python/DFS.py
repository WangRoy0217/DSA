# BFS algorithm in Python

import collections

# BFS algorithm
def dfs(graph, root, visited = None):
    if visited == None:
        visited = set()
    if not root in visited:
        visited.add(root)
        print(root)


        for vertex in set(graph[root]) - visited:
            dfs(graph, vertex, visited)

    return visited



if __name__ == '__main__':
    graph = {
  '5' : ['3','7'],
  '3' : ['2', '4'],
  '7' : ['8'],
  '2' : [],
  '4' : ['8'],
  '8' : []
}
    print("Following is Breadth First Traversal: ")
    dfs(graph, '5')