const canvas = document.getElementById("graphCanvas");
const ctx = canvas.getContext("2d");

function parseInput(input) {
    let graph = {};
    let lines = input.trim().split("\n");

    for (let line of lines) {
        let [node, edges] = line.split(":");
        graph[node.trim()] = [];

        if (edges) {
            let parts = edges.split(",");
            for (let part of parts) {
                let [neighbor, weight] = part.trim().split(" ");
                graph[node.trim()].push({
                    node: neighbor.trim(),
                    weight: parseInt(weight)
                });
            }
        }
    }
    return graph;
}

function dijkstra(graph, start) {
    let dist = {};
    let visited = {};

    for (let node in graph) {
        dist[node] = Infinity;
    }
    dist[start] = 0;

    while (true) {
        let closest = null;

        for (let node in dist) {
            if (!visited[node] &&
                (closest === null || dist[node] < dist[closest])) {
                closest = node;
            }
        }

        if (closest === null) break;

        visited[closest] = true;

        for (let neighbor of graph[closest]) {
            let newDist = dist[closest] + neighbor.weight;
            if (newDist < dist[neighbor.node]) {
                dist[neighbor.node] = newDist;
            }
        }
    }

    return dist;
}

function drawGraph(graph) {
    ctx.clearRect(0, 0, canvas.width, canvas.height);

    let nodes = Object.keys(graph);
    let positions = {};

    let angleStep = (2 * Math.PI) / nodes.length;
    let radius = 150;
    let centerX = canvas.width / 2;
    let centerY = canvas.height / 2;

    nodes.forEach((node, i) => {
        let angle = i * angleStep;
        positions[node] = {
            x: centerX + radius * Math.cos(angle),
            y: centerY + radius * Math.sin(angle)
        };
    });

    // Draw edges
    for (let node in graph) {
        for (let neighbor of graph[node]) {
            let from = positions[node];
            let to = positions[neighbor.node];

            ctx.beginPath();
            ctx.moveTo(from.x, from.y);
            ctx.lineTo(to.x, to.y);
            ctx.stroke();

            // weight label
            let midX = (from.x + to.x) / 2;
            let midY = (from.y + to.y) / 2;
            ctx.fillText(neighbor.weight, midX, midY);
        }
    }

    // Draw nodes
    for (let node in positions) {
        let { x, y } = positions[node];

        ctx.beginPath();
        ctx.arc(x, y, 20, 0, 2 * Math.PI);
        ctx.fillStyle = "#4CAF50";
        ctx.fill();
        ctx.stroke();

        ctx.fillStyle = "white";
        ctx.fillText(node, x - 5, y + 5);
    }
}

function runDijkstra() {
    let input = document.getElementById("inputGraph").value;
    let source = document.getElementById("sourceNode").value.trim();

    let graph = parseInput(input);

    let distances = dijkstra(graph, source);

    drawGraph(graph);

    let outputDiv = document.getElementById("output");
    outputDiv.innerHTML = "<h3>Shortest Distances:</h3>";

    for (let node in distances) {
        outputDiv.innerHTML += `${node}: ${distances[node]} <br>`;
    }
}