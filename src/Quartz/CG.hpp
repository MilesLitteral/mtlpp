class CGFloat {
    Initializers
    init()
    Create an instance initialized to zero.
    init(Float)
    value rounded to the closest representable Self.
    init(Double)
    value rounded to the closest representable Self.
    init(CGFloat)
    Create an instance initialized to value.
    init(Float80)
    value rounded to the closest representable Self.
    init<Source>(Source)
    Creates a new instance from the given value, rounded to the closest possible representation.
    init<Source>(Source)
    Creates a new value, rounded to the closest possible representation.
    init(NSNumber)
    Deprecated
    init<T>(T)
    init(bitPattern: UInt)
    init?<T>(exactly: T)
    init?<Source>(exactly: Source)
    Creates a new instance from the given value, if it can be represented exactly.
    init?<Source>(exactly: Source)
    Creates a new value, if the given integer can be represented exactly.
    init?(exactly: NSNumber)
    init(floatLiteral: CGFloat.NativeType)
    Create an instance initialized to value.
    init(floatLiteral: CGFloat.NativeType)
    Create an instance initialized to value.
    init(from: any Decoder)
    init(integerLiteral: Int)
    Create an instance initialized to value.
    init(nan: CGFloat.RawSignificand, signaling: Bool)
    NaN with specified payload.
    init(sign: FloatingPointSign, exponent: Int, significand: CGFloat)
    Initialize from sign, exponent, and significand.
    init(sign: FloatingPointSign, exponentBitPattern: UInt, significandBitPattern: UInt)
    Combines sign, exponent and significand bit patterns to produce a floating-point value.
    init(signOf: CGFloat, magnitudeOf: CGFloat)
    Creates a new floating-point value using the sign of one value and the magnitude of another.
    init(truncating: NSNumber)
    Instance Properties
    var binade: CGFloat
    The least-magnitude member of the binade of self.
    var bitPattern: UInt
    var customMirror: Mirror
    A mirror that reflects the CGFloat instance.
    var description: String
    A textual representation of self.
    var exponent: Int
    The integer part of the base-r logarithm of the magnitude of self, where r is the radix (2 for binary, 10 for decimal). Implements the IEEE 754 logB operation.
    var exponentBitPattern: UInt
    The raw encoding of the exponent field of the floating-point value.
    var floatingPointClass: FloatingPointClassification
    var hashValue: Int
    The hash value.
    var isCanonical: Bool
    True if and only if self is canonical.
    var isFinite: Bool
    true iff self is zero, subnormal, or normal (not infinity or NaN).
    var isInfinite: Bool
    true iff self is infinity.
    var isNaN: Bool
    true iff self is NaN.
    var isNormal: Bool
    true iff self is normal (not zero, subnormal, infinity, or NaN).
    var isSignalingNaN: Bool
    True if and only if self is a signaling NaN.
    var isSubnormal: Bool
    true iff self is subnormal.
    var isZero: Bool
    true iff self is +0.0 or -0.0.
    var magnitude: CGFloat
    var magnitudeSquared: Double
    var native: CGFloat.NativeType
    The native value.
    var native: CGFloat.NativeType
    The native value.
    var nextDown: CGFloat
    The greatest representable value that compares less than this value.
    var nextUp: CGFloat
    The least representable value that compares greater than self.
    var sign: FloatingPointSign
    minus if the sign bit of self is set, and plus otherwise. Implements the IEEE 754 signbit operation.
    var significand: CGFloat
    The significant digits, or mantissa, of the floating-point number.
    var significandBitPattern: UInt
    The raw encoding of the significand field of the floating-point value.
    var significandWidth: Int
    The number of bits required to represent significand.
    var ulp: CGFloat
    The unit in the last place of self.
    Type Properties
    static var exponentBitCount: Int
    The number of bits used to represent the exponent.
    static var greatestFiniteMagnitude: CGFloat
    The greatest finite number.
    static var infinity: CGFloat
    The positive infinity.
    static var leastNonzeroMagnitude: CGFloat
    The least positive number.
    static var leastNormalMagnitude: CGFloat
    The least positive normal number.
    static var nan: CGFloat
    A quiet NaN.
    static var pi: CGFloat
    The mathematical constant π (3.14159…).
    static var radix: Int
    The radix, or base of exponentiation, for a floating-point type.
    static var signalingNaN: CGFloat
    A signaling NaN (not-a-number).
    static var significandBitCount: Int
    For fixed-width floating-point types, this is the number of fractional significand bits.
    static var ulpOfOne: CGFloat
    The unit in the last place of 1.0.
    static var zero: CGFloat
    The zero value.
    Instance Methods
    func addProduct(CGFloat, CGFloat)
    func addingProduct(CGFloat, CGFloat) -> CGFloat
    Returns the result of adding the product of the two given values to this value, computed without intermediate rounding.
    func advanced(by: CGFloat) -> CGFloat
    Returns a Self x such that self.distance(to: x) approximates n.
    func distance(to: CGFloat) -> CGFloat
    Returns a stride x such that self.advanced(by: x) approximates other.
    func encode(to: any Encoder)
    func formRemainder(dividingBy: CGFloat)
    func formSquareRoot()
    func formTruncatingRemainder(dividingBy: CGFloat)
    Replace self with the remainder of self divided by other using truncating division. Similar to the C standard library function fmod.
    func hash(into: inout Hasher)
    func isEqual(to: CGFloat) -> Bool
    IEEE 754 equality predicate.
    func isLess(than: CGFloat) -> Bool
    IEEE 754 less-than predicate.
    func isLessThanOrEqualTo(CGFloat) -> Bool
    IEEE 754 less-than-or-equal predicate.
    func isTotallyOrdered(belowOrEqualTo: CGFloat) -> Bool
    Returns a Boolean value indicating whether this instance should precede or tie positions with the given value in an ascending sort.
    func negate()
    Replace self with its additive inverse.
    func remainder(dividingBy: CGFloat) -> CGFloat
    Returns the remainder of this value divided by the given value.
    func round()
    Rounds this value to an integral value using “schoolbook rounding.”
    func round(FloatingPointRoundingRule)
    func rounded() -> CGFloat
    Returns this value rounded to an integral value using “schoolbook rounding.”
    func rounded(FloatingPointRoundingRule) -> CGFloat
    Returns this value rounded to an integral value using the specified rounding rule.
    func scale(by: Double)
    func squareRoot() -> CGFloat
    Returns the square root of the value, rounded to a representable value.
    func truncatingRemainder(dividingBy: CGFloat) -> CGFloat
    Returns the remainder of this value divided by the given value using truncating division.
    Type Methods
    static func maximum(CGFloat, CGFloat) -> CGFloat
    Returns the greater of the two given values.
    static func maximumMagnitude(CGFloat, CGFloat) -> CGFloat
    Returns the value with greater magnitude.
    static func minimum(CGFloat, CGFloat) -> CGFloat
    Returns the lesser of the two given values.
    static func minimumMagnitude(CGFloat, CGFloat) -> CGFloat
    Returns the value with lesser magnitude.
    static func random(in: ClosedRange<CGFloat>) -> CGFloat
    Returns a random value within the specified range.
    static func random(in: Range<CGFloat>) -> CGFloat
    Returns a random value within the specified range.
    static func random<T>(in: ClosedRange<CGFloat>, using: inout T) -> CGFloat
    Returns a random value within the specified range, using the given generator as a source for randomness.
    static func random<T>(in: Range<CGFloat>, using: inout T) -> CGFloat
    Returns a random value within the specified range, using the given generator as a source for randomness.
    Operator Functions
    static func != (CGFloat, CGFloat) -> Bool
    Returns a Boolean value indicating whether two values are not equal.
    static func * (CGFloat, CGFloat) -> CGFloat
    static func *= (inout CGFloat, CGFloat)
    static func + (CGFloat) -> CGFloat
    Returns the given number unchanged.
    static func + (CGFloat, CGFloat) -> CGFloat
    static func += (inout CGFloat, CGFloat)
    static func - (CGFloat) -> CGFloat
    Returns the additive inverse of the specified value.
    static func - (CGFloat, CGFloat) -> CGFloat
    static func -= (inout CGFloat, CGFloat)
    static func ... (CGFloat) -> PartialRangeFrom<CGFloat>
    Returns a partial range extending upward from a lower bound.
    static func ... (CGFloat) -> PartialRangeThrough<CGFloat>
    Returns a partial range up to, and including, its upper bound.
    static func ... (CGFloat, CGFloat) -> ClosedRange<CGFloat>
    Returns a closed range that contains both of its bounds.
    static func ..< (CGFloat) -> PartialRangeUpTo<CGFloat>
    Returns a partial range up to, but not including, its upper bound.
    static func ..< (CGFloat, CGFloat) -> Range<CGFloat>
    Returns a half-open range that contains its lower bound but not its upper bound.
    static func / (CGFloat, CGFloat) -> CGFloat
    static func /= (inout CGFloat, CGFloat)
    static func < (CGFloat, CGFloat) -> Bool
    Returns a Boolean value indicating whether the value of the first argument is less than that of the second argument.
    static func <= (CGFloat, CGFloat) -> Bool
    Returns a Boolean value indicating whether the value of the first argument is less than or equal to that of the second argument.
    static func == (CGFloat, CGFloat) -> Bool
    Returns a Boolean value indicating whether two values are equal.
    static func > (CGFloat, CGFloat) -> Bool
    Returns a Boolean value indicating whether the value of the first argument is greater than that of the second argument.
    static func >= (CGFloat, CGFloat) -> Bool
    Returns a Boolean value indicating whether the value of the first argument is greater than or equal to that of the second argument.
}

class CGSize{
    Geometric Properties
var width: Double
A width value.
var height: Double
A height value.
Special Values
static var zero: CGSize
The size whose width and height are both zero.
init()
Creates a size with zero width and height.
Transforming Sizes
func applying(CGAffineTransform) -> CGSize
Returns the height and width resulting from a transformation of an existing height and width.
Alternate Representations
var dictionaryRepresentation: CFDictionary
Returns a dictionary representation of the specified size.
init?(dictionaryRepresentation: CFDictionary)
Creates a size from a canonical dictionary representation.
var debugDescription: String
A textual representation of the size’s dimensions.
var customMirror: Mirror
A representation of the size’s structure and display style for use in debugging.
var customPlaygroundQuickLook: PlaygroundQuickLook
A representation of the size for use in Playgrounds.
Deprecated
Comparing Sizes
func CGSizeEqualToSize(CGSize, CGSize) -> Bool
Returns whether two sizes are equal.
Type Aliases
typealias CGSize.AnimatableData
Initializers
init(width: Double, height: Double)
init(width: Float, height: Float)
Instance Properties
var animatableData: CGSize.AnimatableData
}

class CGVector {
    Special Values
static var zero: CGVector
The vector whose components are both zero.
init()
Creates a vector whose components are both zero.
Geometric Properties
var dx: Double
The x component of the vector.
var dy: Double
The y component of the vector.
Initializers
init(dx: Double, dy: Double)
init(dx: Float, dy: Float)
}

class CGAffineTransform{
    Initializers
init(rotationAngle: CGFloat)
Returns an affine transformation matrix constructed from a rotation value you provide.
init(scaleX: CGFloat, y: CGFloat)
Returns an affine transformation matrix constructed from scaling values you provide.
init(translationX: CGFloat, y: CGFloat)
Returns an affine transformation matrix constructed from translation values you provide.
init()
init(a: Double, b: Double, c: Double, d: Double, tx: Double, ty: Double)
init(a: Float, b: Float, c: Float, d: Float, tx: Float, ty: Float)
Instance Properties
var isIdentity: Bool
Checks whether an affine transform is the identity transform.
var a: Double
The entry at position [1,1] in the matrix.
var b: Double
The entry at position [1,2] in the matrix.
var c: Double
The entry at position [2,1] in the matrix.
var d: Double
The entry at position [2,2] in the matrix.
var tx: Double
The entry at position [3,1] in the matrix.
var ty: Double
The entry at position [3,2] in the matrix.
Type Properties
static var identity: CGAffineTransform
The identity transform.
Instance Methods
func concatenating(CGAffineTransform) -> CGAffineTransform
Returns an affine transformation matrix constructed by combining two existing affine transforms.
func CGAffineTransformEqualToTransform(CGAffineTransform, CGAffineTransform) -> Bool
Checks whether two affine transforms are equal.
func inverted() -> CGAffineTransform
Returns an affine transformation matrix constructed by inverting an existing affine transform.
func rotated(by: CGFloat) -> CGAffineTransform
Returns an affine transformation matrix constructed by rotating an existing affine transform.
func scaledBy(x: CGFloat, y: CGFloat) -> CGAffineTransform
Returns an affine transformation matrix constructed by scaling an existing affine transform.
func translatedBy(x: CGFloat, y: CGFloat) -> CGAffineTransform
Returns an affine transformation matrix constructed by translating an existing affine transform.
}

class CGPoint{
    Creating Point Values
init(x: Double, y: Double)
Creates a point with coordinates specified as floating-point values.
init(x: Int, y: Int)
Creates a point with coordinates specified as integer values.
Special Values
static var zero: CGPoint
The point with location (0,0).
init()
Creates a point with location (0,0).
Geometric Properties
var x: Double
The x-coordinate of the point.
var y: Double
The y-coordinate of the point.
Transforming Points
func applying(CGAffineTransform) -> CGPoint
Returns the point resulting from an affine transformation of an existing point.
Alternate Representations
var dictionaryRepresentation: CFDictionary
Returns a dictionary representation of the specified point.
init?(dictionaryRepresentation: CFDictionary)
Creates a point from a canonical dictionary representation.
var debugDescription: String
A textual representation of the point’s coordinate values.
var customMirror: Mirror
A representation of the point’s structure and display style for use in debugging.
var customPlaygroundQuickLook: PlaygroundQuickLook
A representation of the point for use in Playgrounds.
Deprecated
Comparing Points
func CGPointEqualToPoint(CGPoint, CGPoint) -> Bool
Returns whether two points are equal.
Type Aliases
typealias CGPoint.AnimatableData
Initializers
init(x: Double, y: Double)
init(x: Float, y: Float)
Instance Properties
var animatableData: CGPoint.AnimatableData
Instance Methods
func applying(ProjectionTransform) -> CGPoint
}

class CGRect{
    Creating Rectangle Values
init(origin: CGPoint, size: CGSize)
Creates a rectangle with the specified origin and size.
init(x: Double, y: Double, width: Double, height: Double)
Creates a rectangle with coordinates and dimensions specified as floating-point values.
init(x: Int, y: Int, width: Int, height: Int)
Creates a rectangle with coordinates and dimensions specified as integer values.
init(x: CGFloat, y: CGFloat, width: CGFloat, height: CGFloat)
Creates a rectangle with coordinates and dimensions specified as CGFloat values.
Special Values
static var infinite: CGRect
A rectangle that has infinite extent.
static var null: CGRect
The null rectangle, representing an invalid value.
static var zero: CGRect
The rectangle whose origin and size are both zero.
init()
Creates a rectangle with origin (0,0) and size (0,0).
Basic Geometric Properties
var origin: CGPoint
A point that specifies the coordinates of the rectangle’s origin.
var size: CGSize
A size that specifies the height and width of the rectangle.
Calculated Geometric Properties
var height: CGFloat
Returns the height of a rectangle.
var width: CGFloat
Returns the width of a rectangle.
var minX: CGFloat
Returns the smallest value for the x-coordinate of the rectangle.
var midX: CGFloat
Returns the x- coordinate that establishes the center of a rectangle.
var maxX: CGFloat
Returns the largest value of the x-coordinate for the rectangle.
var minY: CGFloat
Returns the smallest value for the y-coordinate of the rectangle.
var midY: CGFloat
Returns the y-coordinate that establishes the center of the rectangle.
var maxY: CGFloat
Returns the largest value for the y-coordinate of the rectangle.
Creating Derived Rectangles
var standardized: CGRect
Returns a rectangle with a positive width and height.
var integral: CGRect
Returns the smallest rectangle that results from converting the source rectangle values to integers.
func applying(CGAffineTransform) -> CGRect
Applies an affine transform to a rectangle.
func insetBy(dx: CGFloat, dy: CGFloat) -> CGRect
Returns a rectangle that is smaller or larger than the source rectangle, with the same center point.
func offsetBy(dx: CGFloat, dy: CGFloat) -> CGRect
Returns a rectangle with an origin that is offset from that of the source rectangle.
func union(CGRect) -> CGRect
Returns the smallest rectangle that contains the two source rectangles.
func intersection(CGRect) -> CGRect
Returns the intersection of two rectangles.
func divided(atDistance: CGFloat, from: CGRectEdge) -> (slice: CGRect, remainder: CGRect)
Creates two rectangles by dividing the original rectangle.
enum CGRectEdge
Coordinates that establish the edges of a rectangle.
Checking Characteristics
func intersects(CGRect) -> Bool
Returns whether two rectangles intersect.
func contains(CGPoint) -> Bool
Returns whether a rectangle contains a specified point.
func contains(CGRect) -> Bool
Returns whether the first rectangle contains the second rectangle.
var isEmpty: Bool
Returns whether a rectangle has zero width or height, or is a null rectangle.
var isInfinite: Bool
Returns whether a rectangle is infinite.
var isNull: Bool
Returns whether the rectangle is equal to the null rectangle.
Alternate Representations
var dictionaryRepresentation: CFDictionary
Returns a dictionary representation of the provided rectangle.
init?(dictionaryRepresentation: CFDictionary)
Creates a rectangle from a canonical dictionary representation.
var debugDescription: String
var customMirror: Mirror
A representation of the rectangle’s structure and display style for use in debugging.
var customPlaygroundQuickLook: PlaygroundQuickLook
A representation of the rectangle for use in Playgrounds.
Deprecated
Comparing Rectangles
func CGRectEqualToRect(CGRect, CGRect) -> Bool
Returns whether two rectangles are equal in size and position.
Type Aliases
typealias CGRect.AnimatableData
Instance Properties
var animatableData: CGRect.AnimatableData
Instance Methods
func clip()
func fill(using: NSCompositingOperation)
func frame(withWidth: CGFloat, using: NSCompositingOperation)
func inset(by: UIEdgeInsets) -> CGRect
Adjusts a rectangle by the given edge insets.
}