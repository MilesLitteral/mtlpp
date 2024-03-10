#include "ns.hpp"
namespace quartz{
class Layer : ns::Object {
        /*Creating a Layer
        init()
        Returns an initialized CALayer object.
        init(layer: Any)
        Override to copy or initialize custom fields of the specified layer.
        init(remoteClientId: UInt32)
        Initializes a layer with a remote client ID.
        Accessing Related Layer Objects
        func presentation() -> Self?
        Returns a copy of the presentation layer object that represents the state of the layer as it currently appears onscreen.
        func model() -> Self
        Returns the model layer object associated with the receiver, if any.
        Accessing the Delegate
        var delegate: (any CALayerDelegate)?
        The layer’s delegate object.
        Providing the Layer’s Content
        var contents: Any?
        An object that provides the contents of the layer. Animatable.
        var contentsRect: CGRect
        The rectangle, in the unit coordinate space, that defines the portion of the layer’s contents that should be used. Animatable.
        var contentsCenter: CGRect
        The rectangle that defines how the layer contents are scaled if the layer’s contents are resized. Animatable.
        func display()
        Reloads the content of this layer.
        func draw(in: CGContext)
        Draws the layer’s content using the specified graphics context.
        Modifying the Layer’s Appearance
        var contentsGravity: CALayerContentsGravity
        A constant that specifies how the layer's contents are positioned or scaled within its bounds.
        Contents Gravity Values
        The contents gravity constants specify the position of the content object when the layer bounds is larger than the bounds of the content object. They are used by the contentsGravity property.
        var opacity: Float
        The opacity of the receiver. Animatable.
        var isHidden: Bool
        A Boolean indicating whether the layer is displayed. Animatable.
        var masksToBounds: Bool
        A Boolean indicating whether sublayers are clipped to the layer’s bounds. Animatable.
        var mask: CALayer?
        An optional layer whose alpha channel is used to mask the layer’s content.
        var isDoubleSided: Bool
        A Boolean indicating whether the layer displays its content when facing away from the viewer. Animatable.
        var cornerRadius: CGFloat
        The radius to use when drawing rounded corners for the layer’s background. Animatable.
        var maskedCorners: CACornerMask
        struct CACornerMask
        var borderWidth: CGFloat
        The width of the layer’s border. Animatable.
        var borderColor: CGColor?
        The color of the layer’s border. Animatable.
        var backgroundColor: CGColor?
        The background color of the receiver. Animatable.
        var shadowOpacity: Float
        The opacity of the layer’s shadow. Animatable.
        var shadowRadius: CGFloat
        The blur radius (in points) used to render the layer’s shadow. Animatable.
        var shadowOffset: CGSize
        The offset (in points) of the layer’s shadow. Animatable.
        var shadowColor: CGColor?
        The color of the layer’s shadow. Animatable.
        var shadowPath: CGPath?
        The shape of the layer’s shadow. Animatable.
        var style: [AnyHashable : Any]?
        An optional dictionary used to store property values that aren't explicitly defined by the layer.
        var allowsEdgeAntialiasing: Bool
        A Boolean indicating whether the layer is allowed to perform edge antialiasing.
        var allowsGroupOpacity: Bool
        A Boolean indicating whether the layer is allowed to composite itself as a group separate from its parent.
        Layer Filters
        var filters: [Any]?
        An array of Core Image filters to apply to the contents of the layer and its sublayers. Animatable.
        var compositingFilter: Any?
        A CoreImage filter used to composite the layer and the content behind it. Animatable.
        var backgroundFilters: [Any]?
        An array of Core Image filters to apply to the content immediately behind the layer. Animatable.
        var minificationFilter: CALayerContentsFilter
        The filter used when reducing the size of the content.
        var minificationFilterBias: Float
        The bias factor used by the minification filter to determine the levels of detail.
        var magnificationFilter: CALayerContentsFilter
        The filter used when increasing the size of the content.
        Configuring the Layer’s Rendering Behavior
        var isOpaque: Bool
        A Boolean value indicating whether the layer contains completely opaque content.
        var edgeAntialiasingMask: CAEdgeAntialiasingMask
        A bitmask defining how the edges of the receiver are rasterized.
        func contentsAreFlipped() -> Bool
        Returns a Boolean indicating whether the layer content is implicitly flipped when rendered.
        var isGeometryFlipped: Bool
        A Boolean that indicates whether the geometry of the layer and its sublayers is flipped vertically.
        var drawsAsynchronously: Bool
        A Boolean indicating whether drawing commands are deferred and processed asynchronously in a background thread.
        var shouldRasterize: Bool
        A Boolean that indicates whether the layer is rendered as a bitmap before compositing. Animatable
        var rasterizationScale: CGFloat
        The scale at which to rasterize content, relative to the coordinate space of the layer. Animatable
        var contentsFormat: CALayerContentsFormat
        A hint for the desired storage format of the layer contents.
        func render(in: CGContext)
        Renders the layer and its sublayers into the specified context.
        Modifying the Layer Geometry
        var frame: CGRect
        The layer’s frame rectangle.
        var bounds: CGRect
        The layer’s bounds rectangle. Animatable.
        var position: CGPoint
        The layer’s position in its superlayer’s coordinate space. Animatable.
        var zPosition: CGFloat
        The layer’s position on the z axis. Animatable.
        var anchorPointZ: CGFloat
        The anchor point for the layer’s position along the z axis. Animatable.
        var anchorPoint: CGPoint
        Defines the anchor point of the layer's bounds rectangle. Animatable.
        var contentsScale: CGFloat
        The scale factor applied to the layer.
        Managing the Layer’s Transform
        var transform: CATransform3D
        The transform applied to the layer’s contents. Animatable.
        var sublayerTransform: CATransform3D
        Specifies the transform to apply to sublayers when rendering. Animatable.
        func affineTransform() -> CGAffineTransform
        Returns an affine version of the layer’s transform.
        func setAffineTransform(CGAffineTransform)
        Sets the layer’s transform to the specified affine transform.
        Managing the Layer Hierarchy
        var sublayers: [CALayer]?
        An array containing the layer’s sublayers.
        var superlayer: CALayer?
        The superlayer of the layer.
        func addSublayer(CALayer)
        Appends the layer to the layer’s list of sublayers.
        func removeFromSuperlayer()
        Detaches the layer from its parent layer.
        func insertSublayer(CALayer, at: UInt32)
        Inserts the specified layer into the receiver’s list of sublayers at the specified index.
        func insertSublayer(CALayer, below: CALayer?)
        Inserts the specified sublayer below a different sublayer that already belongs to the receiver.
        func insertSublayer(CALayer, above: CALayer?)
        Inserts the specified sublayer above a different sublayer that already belongs to the receiver.
        func replaceSublayer(CALayer, with: CALayer)
        Replaces the specified sublayer with a different layer object.
        Updating Layer Display
        func setNeedsDisplay()
        Marks the layer’s contents as needing to be updated.
        func setNeedsDisplay(CGRect)
        Marks the region within the specified rectangle as needing to be updated.
        var needsDisplayOnBoundsChange: Bool
        A Boolean indicating whether the layer contents must be updated when its bounds rectangle changes.
        func displayIfNeeded()
        Initiates the update process for a layer if it is currently marked as needing an update.
        func needsDisplay() -> Bool
        Returns a Boolean indicating whether the layer has been marked as needing an update.
        class func needsDisplay(forKey: String) -> Bool
        Returns a Boolean indicating whether changes to the specified key require the layer to be redisplayed.
        Layer Animations
        func add(CAAnimation, forKey: String?)
        Add the specified animation object to the layer’s render tree.
        func animation(forKey: String) -> CAAnimation?
        Returns the animation object with the specified identifier.
        func removeAllAnimations()
        Remove all animations attached to the layer.
        func removeAnimation(forKey: String)
        Remove the animation object with the specified key.
        func animationKeys() -> [String]?
        Returns an array of strings that identify the animations currently attached to the layer.
        Managing Layer Resizing and Layout
        var layoutManager: (any CALayoutManager)?
        The object responsible for laying out the layer’s sublayers.
        func setNeedsLayout()
        Invalidates the layer’s layout and marks it as needing an update.
        func layoutSublayers()
        Tells the layer to update its layout.
        func layoutIfNeeded()
        Recalculate the receiver’s layout, if required.
        func needsLayout() -> Bool
        Returns a Boolean indicating whether the layer has been marked as needing a layout update.
        var autoresizingMask: CAAutoresizingMask
        A bitmask defining how the layer is resized when the bounds of its superlayer changes.
        func resize(withOldSuperlayerSize: CGSize)
        Informs the receiver that the size of its superlayer changed.
        func resizeSublayers(withOldSize: CGSize)
        Informs the receiver’s sublayers that the receiver’s size has changed.
        func preferredFrameSize() -> CGSize
        Returns the preferred size of the layer in the coordinate space of its superlayer.
        Managing Layer Constraints
        var constraints: [CAConstraint]?
        The constraints used to position current layer’s sublayers.
        func addConstraint(CAConstraint)
        Adds the specified constraint to the layer.
        Getting the Layer’s Actions
        func action(forKey: String) -> (any CAAction)?
        Returns the action object assigned to the specified key.
        var actions: [String : any CAAction]?
        A dictionary containing layer actions.
        class func defaultAction(forKey: String) -> (any CAAction)?
        Returns the default action for the current class.
        Mapping Between Coordinate and Time Spaces
        func convert(CGPoint, from: CALayer?) -> CGPoint
        Converts the point from the specified layer’s coordinate system to the receiver’s coordinate system.
        func convert(CGPoint, to: CALayer?) -> CGPoint
        Converts the point from the receiver’s coordinate system to the specified layer’s coordinate system.
        func convert(CGRect, from: CALayer?) -> CGRect
        Converts the rectangle from the specified layer’s coordinate system to the receiver’s coordinate system.
        func convert(CGRect, to: CALayer?) -> CGRect
        Converts the rectangle from the receiver’s coordinate system to the specified layer’s coordinate system.
        func convertTime(CFTimeInterval, from: CALayer?) -> CFTimeInterval
        Converts the time interval from the specified layer’s time space to the receiver’s time space.
        func convertTime(CFTimeInterval, to: CALayer?) -> CFTimeInterval
        Converts the time interval from the receiver’s time space to the specified layer’s time space
        Hit Testing
        func hitTest(CGPoint) -> CALayer?
        Returns the farthest descendant of the receiver in the layer hierarchy (including itself) that contains the specified point.
        func contains(CGPoint) -> Bool
        Returns whether the receiver contains a specified point.
        Scrolling
        var visibleRect: CGRect
        The visible region of the layer in its own coordinate space.
        func scroll(CGPoint)
        Initiates a scroll in the layer’s closest ancestor scroll layer so that the specified point lies at the origin of the scroll layer.
        func scrollRectToVisible(CGRect)
        Initiates a scroll in the layer’s closest ancestor scroll layer so that the specified rectangle becomes visible.
        Identifying the Layer
        var name: String?
        The name of the receiver.
        Key-Value Coding Extensions
        func shouldArchiveValue(forKey: String) -> Bool
        Returns a Boolean indicating whether the value of the specified key should be archived.
        class func defaultValue(forKey: String) -> Any?
        Specifies the default value associated with the specified key.
        Constants
        struct CAAutoresizingMask
        These constants are used by the autoresizingMask property.
        Action Identifiers
        These constants are the predefined action identifiers used by action(forKey:), add(_:forKey:), defaultAction(forKey:), removeAnimation(forKey:), Layer Filters, and the CAAction protocol method run(forKey:object:arguments:).
        struct CAEdgeAntialiasingMask
        This mask is used by the edgeAntialiasingMask property.
        Identity Transform
        Defines the identity transform matrix used by Core Animation.
        Scaling Filters
        These constants specify the scaling filters used by magnificationFilter and minificationFilter.
        struct CATransform3D
        The standard transform matrix used throughout Core Animation.
        Instance Properties
        var cornerCurve: CALayerCornerCurve
        var wantsDynamicContentScaling: Bool
        var wantsExtendedDynamicRangeContent: Bool
        Type Methods
        class func cornerCurveExpansionFactor(CALayerCornerCurve) -> CGFloat*/
    }
}