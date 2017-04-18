using System;
using Gtk;

namespace Harley
{
	public class Harley : Window
	{
		private ISituation BattleSituation;
		private ISituation Overworld;
		private Player CurrentPlayer;
		private ISituation CurrentSituation;

		public Harley () : base("Harley")
		{
			SetDefaultSize (320, 240);
			SetPosition (WindowPosition.Center);

			DeleteEvent += delegate {
				Application.Quit ();
			};


			CurrentPlayer = new Player ();

			BattleSituation = new Battle (CurrentPlayer);
			Overworld = new Overworld (CurrentPlayer);

			CurrentSituation = Overworld;

			GLib.Timeout.Add (33, new GLib.TimeoutHandler (Update));

			SetSizeRequest (320, 240);

			Show();
		}

		public static void Main(String[] args)
		{
			Application.Init ();
			new Harley ();
			Application.Run ();
		}

		protected override bool OnDrawn (Cairo.Context cr)
		{
			CurrentSituation.Redraw (cr);
			return base.OnDrawn (cr);
		}

		protected override bool OnKeyPressEvent (Gdk.EventKey evnt)
		{
			switch (evnt.Key) {
			case Gdk.Key.w:
				CurrentSituation.StartUp ();
				break;
			case Gdk.Key.a:
				CurrentSituation.StartLeft ();
				break;
			case Gdk.Key.s:
				CurrentSituation.StartDown ();
				break;
			case Gdk.Key.d:
				CurrentSituation.StartRight ();
				break;
			}

			return base.OnKeyPressEvent (evnt);
		}

		protected override bool OnKeyReleaseEvent (Gdk.EventKey evnt)
		{
			switch (evnt.Key) {
			case Gdk.Key.w:
				CurrentSituation.StopUp ();
				break;
			case Gdk.Key.a:
				CurrentSituation.StopLeft ();
				break;
			case Gdk.Key.s:
				CurrentSituation.StopDown ();
				break;
			case Gdk.Key.d:
				CurrentSituation.StopRight ();
				break;
			}

			return base.OnKeyPressEvent (evnt);
		}

		public bool Update(){
			CurrentSituation.Update ();
			QueueDraw ();
			return true;
		}
	}
}

