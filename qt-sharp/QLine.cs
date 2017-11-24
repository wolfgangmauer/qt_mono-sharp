using System;

namespace Qt
{
	public class Line : Frame
	{
		protected Line (IntPtr raw) : base(raw) {}

		public Line (Widget parent) : base(parent)
		{
			FrameShadow = Shadow.Sunken;
		}

		public Orientation Orientation {
			get 
			{
				return FrameShape == Shape.HLine ? Orientation.Horizontal : Orientation.Vertical;
			}
			set 
			{
				if (value == Orientation.Horizontal)
					FrameShape = Shape.HLine;
				else
					FrameShape = Shape.VLine;
			}
		}
	}
}

