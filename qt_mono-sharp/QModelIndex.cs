using System;

namespace Qt
{
	public class ModelIndex
	{
		IntPtr raw;

		public IntPtr Handle { get { return raw; } }

		public ModelIndex (IntPtr raw)
		{
			this.raw = raw;
		}
	}
}

