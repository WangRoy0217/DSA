import collections


def bts(graph, root):
	queue, visited = collections.deque([root]), set()
	visited.add(root)
	while queue:
		vertex = queue.popleft()
		print(vertex, end="->")

		for linkvertex in graph:
			if not linkvertex in visited:
				queue.append(linkvertex)
				visited.add(linkvertex)


if __name__ == "__main__":
	dic = {0:[1,2], 1:[2], 2:[3], 3:[1,2]}
	bts(dic, 0)

