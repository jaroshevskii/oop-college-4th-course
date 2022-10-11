//
// Practice: Practical work 3
//

import Foundation

struct Point {
  var x = 0.0
  var y = 0.0

  func distanceTo(_ point: Point) -> Double {
    return sqrt(pow(point.x - x, 2) + pow(point.y - y, 2));
  }
}

class Trapeze {
  let a: Point
  let b: Point
  let c: Point
  let d: Point

  init(a: Point, b: Point, c: Point, d: Point) {
    self.a = a
    self.b = b
    self.c = c
    self.d = d
  }

  func perimeter() -> Double {
    return a.distanceTo(b) + b.distanceTo(c) + c.distanceTo(d) + d.distanceTo(a);
  }

  func height() -> Double {
    return b.distanceTo(Point(x: b.x, y: a.y));
  }
   
  func area() -> Double {
    return (a.distanceTo(d) + b.distanceTo(c)) / 2.0 * height();
  }

  func print() {
    Swift.print("""
    Sides lenght:
      AB: \(a.distanceTo(b))
      BC: \(b.distanceTo(c))
      CD: \(c.distanceTo(d))
      DA: \(d.distanceTo(a))
    Perimeter: \(perimeter())
    Area:      \(area())

    """)
  }
}

// MARK: Main

var trapezes = [Trapeze]()

let trapezesCount = 10
let range = 0.0...100.0
for _ in 1...trapezesCount {
  trapezes.append(Trapeze(
    a: Point(x: Double.random(in: range), y: Double.random(in: range)),
    b: Point(x: Double.random(in: range), y: Double.random(in: range)),
    c: Point(x: Double.random(in: range), y: Double.random(in: range)),
    d: Point(x: Double.random(in: range), y: Double.random(in: range))
  ))
}

var areaAverageSum: Double {
  var areaSum = 0.0
  for trapeze in trapezes {
    areaSum += trapeze.area();
  }
  return areaSum / Double(trapezesCount)
}

var areasCount: Int {
  var counter = 0
  for trapeze in trapezes {
    if trapeze.area() > areaAverageSum {
      trapeze.print()
      counter += 1
    }
  }
  return counter
}

print("Areas count: \(areasCount)\n")
