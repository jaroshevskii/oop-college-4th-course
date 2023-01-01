//
// Object-oriented programing (college 4th course)
// Practice: Practical work 7
//

extension LosslessStringConvertible {
  /// Returns a value read from standard input.
  static func read(lable: String = "", nestingLevel: Int = 0) -> Self {
    let indent = String(repeating: " ", count: nestingLevel * 2)
    let decor = lable.isEmpty ? "\(indent)> " : "\(indent)> \(lable) = "

    while true {
      print(decor, terminator: "")
      if let rawValue = readLine() {
        if let value = Self(rawValue) {
          return value
        } else {
          print("Error: Value must be '\(type(of: self))'")
        }
      } else {
        fatalError("Current line or until EOF is reached")
      }
    }
  }
}

extension LosslessStringConvertible where Self: Comparable {
  /// Returns a value within the specified range read from standard input.
  static func read(in range: ClosedRange<Self>, lable: String = "", nestingLevel: Int = 0) -> Self {
    while true {
      let value = read(lable: lable, nestingLevel: nestingLevel)
      if range.contains(value) {
        return value
      } else {
        print("Error: Value must be in the range '\(range)'")
      }
    }
  }
}

class Transportation {
  enum CargoType {
    case usual
    case oversized
    case fireHazard

    func description() -> String {
      switch self {
      case .usual:
        return "Usual"
      case .oversized:
        return "Oversized"
      case .fireHazard:
        return "Fire hazard"
      }
    }

    /// Returns a `CargoType` read from standard input.
    static func read(lable: String = "Cargo type", nestingLevel: Int = 0) -> CargoType {
      let indent = String(repeating: " ", count: nestingLevel * 2)
      Swift.print("\(indent)> \(lable)")

      let cargoTypes: [CargoType] = [.usual, .oversized, .fireHazard]
      for (index, cargoType) in cargoTypes.enumerated() {
        Swift.print("\(indent)    \(index + 1). \(cargoType.description())")
      }

      let choise = Int.read(in: 1...cargoTypes.count, nestingLevel: nestingLevel)
      return cargoTypes[choise - 1]
    }
  }

  let cargoType: CargoType
  let cargoMass: Double
  let distance: Int

  init(cargoType: CargoType, cargoMass: Double, distance: Int) {
    self.cargoType = cargoType
    self.cargoMass = cargoMass
    self.distance = distance
  }

  /// Returns a `Transportation` read from standard input.
  static func read(lable: String = "Transportation", nestingLevel: Int = 0) -> Transportation {
    let indent = String(repeating: " ", count: nestingLevel * 2)
    Swift.print("\(indent)> \(lable)")
    return Transportation(
      cargoType: CargoType.read(nestingLevel: nestingLevel + 1),
      cargoMass: Double.read(
        in: 1...100_000, lable: "Cargo mass (kg)", nestingLevel: nestingLevel + 1
      ),
      distance: Int.read(in: 1...100_000, lable: "Distance (km)", nestingLevel: nestingLevel + 1)
    )
  }

  /// Writes the textual representations of the `Transportation` into the standard output.
  func print(terminator: String = "\n") {
    Swift.print(
      """
      Transportation:
        Cargo type: \(cargoType.description())
        Cargo mass: \(cargoMass)
        Distance:   \(distance)
      """, terminator: terminator)
  }
}

class Trucks {
  var transportations: [Transportation]

  init(transportations: [Transportation] = []) {
    self.transportations = transportations
  }

  func append() {
    transportations.append(Transportation.read(lable: "New transportation"))
  }

  func remove() {
    if transportations.isEmpty {
      Swift.print("Note: Empty")
    } else {
      let index = Int.read(in: 0...(transportations.count - 1), lable: "Index")
      transportations.remove(at: index)
    }
  }

  /// Writes the textual representations of the `Trucks` into the standard output.
  func print(cargoType: Transportation.CargoType? = nil, terminator: String = "\n") {
    var isTerminationFound = false
    if transportations.isEmpty {
      Swift.print("Note: Empty", terminator: terminator)
    } else {
      let separator = String(repeating: "-", count: 80)
      for transportation in transportations {
        if cargoType == nil || cargoType == transportation.cargoType {
          isTerminationFound = true
          Swift.print(separator)
          transportation.print()
        }
      }
      if isTerminationFound {
        Swift.print(separator, terminator: terminator)
      } else {
        Swift.print("Note: Empty", terminator: terminator)
      }
    }
  }

  /// Writes the textual representations of the `Trucks` into the standard output.
  func print(cargoMass: Double, terminator: String = "\n") {
    var isTerminationFound = false
    if transportations.isEmpty {
      Swift.print("Note: Empty", terminator: terminator)
    } else {
      let separator = String(repeating: "-", count: 80)
      for transportation in transportations {
        if transportation.cargoMass > cargoMass {
          isTerminationFound = true
          Swift.print(separator)
          transportation.print()
        }
      }
      if isTerminationFound {
        Swift.print(separator, terminator: terminator)
      } else {
        Swift.print("Note: Empty", terminator: terminator)
      }
    }
  }

  func printSortedByTransportationsDistance(terminator: String = "\n") {
    Trucks(
      transportations: transportations.sorted { $0.distance > $1.distance }
    ).print(terminator: terminator)
  }
}

// MARK: Main

print(
  """
       ______                 __
      /_  __/____ __ __ ____ / /__ ___
       / /  / __// // // __//  '_/(_-<
      /_/  /_/   \\_,_/ \\__//_/\\_\\/___/
  """, terminator: "\n\n")

var trucks = Trucks()

menu: while true {
  print(
    """
    > Menu:
        1. Append
        2. Remove
        3. Print
        4. Print trucks with a given cargo type
        5. Print sorted trucks by transportation distance
        6. Print trucks which have a cargo mass greater than the given
        7. Exit
    """)
  let choise = Int.read(in: 0...7)
  print()  // Empty line.

  switch choise {
  case 0:
    print("  Created with ❤️ by jaroshevskii", terminator: "\n\n")
  case 1:
    trucks.append()
    print()  // Empty line.
  case 2:
    trucks.remove()
    print()  // Empty line.
  case 3:
    trucks.print(terminator: "\n\n")
  case 4:
    let cargoType = Transportation.CargoType.read()
    print()  // Empty line.
    trucks.print(cargoType: cargoType, terminator: "\n\n")
  case 5:
    trucks.printSortedByTransportationsDistance(terminator: "\n\n")
  case 6:
    let cargoMass = Double.read(in: 1...100_000, lable: "Cargo mass (kg)")
    print()  // Empty line.
    trucks.print(cargoMass: cargoMass, terminator: "\n\n")
  case 7:  // Exit.
    print("  (* ^ ω ^) goodbye", terminator: "\n\n")
    break menu
  default:
    fatalError("Invalid choise")
  }
}
