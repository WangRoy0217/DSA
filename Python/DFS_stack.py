# BFS algorithm in Python

import collections

# BFS algorithm
def dfs(graph, root):
    stack, visited = collections.deque([root]), set()
    


    while(stack):
        vertex = stack.pop()
        visited.add(vertex)
        print(vertex, end = "->")

        for linkvertex in set(graph[vertex]) - visited:
            stack.append(linkvertex)


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