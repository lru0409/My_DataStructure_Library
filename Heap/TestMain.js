import Heap from './Heap.js';

const minHeap = new Heap((a, b) => a - b);
const maxHeap = new Heap((a, b) => b - a);

const input = [3, 1, 2];
for (let i = 0; i < input.length; i++) {
	minHeap.push(input[i]);
	maxHeap.push(input[i]);
}

console.log('minHeap: ');
while (minHeap.size()) {
	console.log(minHeap.pop());
}

console.log('maxHeap: ');
while (maxHeap.size()) {
	console.log(maxHeap.pop());
}