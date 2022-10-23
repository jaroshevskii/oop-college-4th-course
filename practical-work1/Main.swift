//
// Object-oriented programing (college 4th course)
// Practical work 1
//

import Foundation

class Triangle {
  let a, b, c: Double

  var area: Double {
    let semiPerimeter = (a + b + c) / 2.0
    return sqrt(semiPerimeter * (semiPerimeter - a) * (semiPerimeter - b) * (semiPerimeter - c))
  }

  init(a: Double, b: Double, c: Double) {
    self.a = a
    self.b = b
    self.c = c
  }

  /// Writes the textual representations into the standard output.
  func print(terminator: String = "\n") {
    Swift.print(
      """
      Triangle: a = \(a), b = \(b), c = \(c)
        Area: \(area)
      """, terminator: terminator)
  }
}

class Box {
  /// First longest side of a box.
  var lenght: Double
  /// Second longest dise of a box.
  var width: Double
  /// Distance from the top of the box to the ground. The height of a box is also known as the depth.
  var height: Double

  /// Amount of space, measured in cubic units that a 3D object or material takes up.
  var volume: Double { lenght * width * height }

  init(width: Double, height: Double, lenght: Double) {
    self.lenght = lenght
    self.width = width
    self.height = height
  }

  /// Writes the textual representations into the standard output.
  func print(terminator: String = "\n") {
    Swift.print(
      """
      Box: lenght = \(lenght), width = \(width), height = \(height)
        Volume: \(volume)
      """, terminator: terminator)
  }
}

// MARK: Main

Triangle(a: 3, b: 3, c: 3).print(terminator: "\n\n")

Box(width: 1, height: 2, lenght: 3).print()
