using System;
using System.Runtime.CompilerServices;
using System.Xml.Serialization;

namespace Qt
{
    public enum PolicyFlag {
		GrowFlag = 1,
		ExpandFlag = 2,
		ShrinkFlag = 4,
		IgnoreFlag = 8
	};

	public enum Policy
	{
		[XmlEnum("Fixed")]
		Fixed = 0,
		[XmlEnum("Minimum")]
		Minimum = PolicyFlag.GrowFlag,
		[XmlEnum("Maximum")]
		Maximum = PolicyFlag.ShrinkFlag,
		Preferred = PolicyFlag.GrowFlag | PolicyFlag.ShrinkFlag,
		MinimumExpanding = PolicyFlag.GrowFlag | PolicyFlag.ExpandFlag,
		Expanding = PolicyFlag.GrowFlag | PolicyFlag.ShrinkFlag | PolicyFlag.ExpandFlag,
		Ignored = PolicyFlag.ShrinkFlag | PolicyFlag.GrowFlag | PolicyFlag.IgnoreFlag
	};

	[Serializable]
	[XmlRoot("sizepolicy", Namespace = "", IsNullable = false)]
	public class SizePolicy
	{
		enum SizePolicyMasks {
			HSize = 4,
			HMask = 0x0f,
			VMask = HMask << HSize,
			CTShift = 9,
			CTSize = 5,
			CTMask = ((0x1 << CTSize) - 1) << CTShift,
			WFHShift = CTShift + CTSize,
			UnusedShift = WFHShift + 1,
			UnusedSize = 1
		};

		public enum ControlTypeEnum {
			DefaultType      = 0x00000001,
			ButtonBox        = 0x00000002,
			CheckBox         = 0x00000004,
			ComboBox         = 0x00000008,
			Frame            = 0x00000010,
			GroupBox         = 0x00000020,
			Label            = 0x00000040,
			Line             = 0x00000080,
			LineEdit         = 0x00000100,
			PushButton       = 0x00000200,
			RadioButton      = 0x00000400,
			Slider           = 0x00000800,
			SpinBox          = 0x00001000,
			TabWidget        = 0x00002000,
			ToolButton       = 0x00004000
		};

		[MethodImpl( MethodImplOptions.InternalCall )]
		protected static extern IntPtr qt_sizepolicy_new ();
		[MethodImpl( MethodImplOptions.InternalCall )]
		protected static extern IntPtr qt_sizepolicy_new_with_policy (Policy horizontal, Policy vertical);
		[MethodImpl( MethodImplOptions.InternalCall )]
		protected static extern IntPtr qt_sizepolicy_new_with_controltype (Policy horizontal, Policy vertical, ControlTypeEnum type);

		[XmlIgnore]
		public IntPtr Handle;

		public SizePolicy (IntPtr raw)
		{
			Handle = raw;
		}

		public SizePolicy ()
		{
			Handle = qt_sizepolicy_new ();
		}

		public SizePolicy(Policy horizontal, Policy vertical)
		{
			Handle = qt_sizepolicy_new_with_policy (horizontal, vertical);
		}

		public SizePolicy(Policy horizontal, Policy vertical, ControlTypeEnum type)
		{
			Handle = qt_sizepolicy_new_with_controltype (horizontal, vertical, type);
		}

		[MethodImpl( MethodImplOptions.InternalCall )]
		protected static extern Policy qt_sizepolicy_horizontal_get (IntPtr raw);
		[MethodImpl( MethodImplOptions.InternalCall )]
		protected static extern void qt_sizepolicy_horizontal_set (IntPtr raw, Policy horizontal);
		[XmlAttribute("hsizetype")]
		public Policy HorizontalPolicy
		{
			get{
				return qt_sizepolicy_horizontal_get(Handle);
			}
			set{
				qt_sizepolicy_horizontal_set (Handle, value);
			}
		}

		[MethodImpl( MethodImplOptions.InternalCall )]
		protected static extern Policy qt_sizepolicy_vertical_get (IntPtr raw);
		[MethodImpl( MethodImplOptions.InternalCall )]
		protected static extern void qt_sizepolicy_vertical_set (IntPtr raw, Policy vertical);
		[XmlAttribute("vsizetype")]
		public Policy VerticalPolicy
		{
			get{
				return qt_sizepolicy_vertical_get(Handle);
			}
			set{
				qt_sizepolicy_vertical_set (Handle, value);
			}
		}

		[MethodImpl( MethodImplOptions.InternalCall )]
		protected static extern ControlTypeEnum qt_sizepolicy_controltype_get (IntPtr raw);
		[MethodImpl( MethodImplOptions.InternalCall )]
		protected static extern void qt_sizepolicy_controltype_set (IntPtr raw, ControlTypeEnum controlType);
		public ControlTypeEnum ControlType 
		{
			get{
				return qt_sizepolicy_controltype_get(Handle);
			}
			set{
				qt_sizepolicy_controltype_set (Handle, value);
			}
		}

		[MethodImpl( MethodImplOptions.InternalCall )]
		protected static extern Orientation qt_sizepolicy_expanding_directions (IntPtr raw);
		Orientation ExpandingDirections()
		{
			return qt_sizepolicy_expanding_directions (Handle);
		}

		[MethodImpl( MethodImplOptions.InternalCall )]
		protected static extern bool qt_sizepolicy_heightforwidth_get (IntPtr raw);
		[MethodImpl( MethodImplOptions.InternalCall )]
		protected static extern void qt_sizepolicy_heightforwidth_set (IntPtr raw, bool heightForWidth);
		public bool HeightForWidth 
		{
			get
			{
				return qt_sizepolicy_heightforwidth_get(Handle); 
			}
			set
			{
				qt_sizepolicy_heightforwidth_set(Handle, value);  
			}
		}

		[MethodImpl( MethodImplOptions.InternalCall )]
		protected static extern bool qt_sizepolicy_widthforheight_get (IntPtr raw);
		[MethodImpl( MethodImplOptions.InternalCall )]
		protected static extern void qt_sizepolicy_widthforheight_set (IntPtr raw, bool widthForHeight);
		public bool WidthForHeight
		{
			get
			{
				return qt_sizepolicy_widthforheight_get(Handle); 
			}
			set
			{
				qt_sizepolicy_widthforheight_set(Handle, value);  
			}
		}

		[MethodImpl( MethodImplOptions.InternalCall )]
		protected static extern int qt_sizepolicy_horizontalstretch_get (IntPtr raw);
		[MethodImpl( MethodImplOptions.InternalCall )]
		protected static extern void qt_sizepolicy_horizontalstretch_set (IntPtr raw, int horizontalStretch);
		[XmlAttribute("horstretch")]
		public int HorizontalStretch {
			get
			{
				return qt_sizepolicy_horizontalstretch_get(Handle); 
			}
			set
			{
				qt_sizepolicy_horizontalstretch_set(Handle, value);  
			}
		}

		[MethodImpl( MethodImplOptions.InternalCall )]
		protected static extern int qt_sizepolicy_verticalstretch_get (IntPtr raw);
		[MethodImpl( MethodImplOptions.InternalCall )]
		protected static extern void qt_sizepolicy_verticalstretch_set (IntPtr raw, int verticalStretch);
		[XmlAttribute("verstretch")]
		public int VerticalStretch {
			get
			{
				return qt_sizepolicy_verticalstretch_get(Handle); 
			}
			set
			{
				qt_sizepolicy_verticalstretch_set(Handle, value);  
			}
		}
	}
}

