using System;
using Gtk;

namespace Harley
{
	public class Harley : Window
	{
		private static int BATTLE = 1;
		private static int OVERWORLD = 0;
		private ISituation BattleSituation;
		private ISituation Overworld;
		private Player CurrentPlayer;
		private int CurrentSituation;

		public Harley () : base("Center")
		{
			SetDefaultSize (320, 230);
			SetPosition (WindowPosition.Center);

			DeleteEvent += delegate {
				Application.Quit ();
			};

			BattleSituation = new Battle ();

			CurrentSituation = BATTLE;

			CurrentPlayer = new Player ();

			GLib.Timeout.Add (33, new GLib.TimeoutHandler (SetRedraw));

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
			if (CurrentSituation == BATTLE) {
				BattleSituation.Redraw (cr, CurrentPlayer);
			}
			return base.OnDrawn (cr);
		}

		protected override bool OnKeyPressEvent (Gdk.EventKey evnt)
		{
			switch (evnt.Key) {
			case Gdk.Key.w:
				CurrentPlayer.MoveUp ();
				break;
			case Gdk.Key.a:
				CurrentPlayer.MoveLeft ();
				break;
			case Gdk.Key.s:
				CurrentPlayer.MoveDown ();
				break;
			case Gdk.Key.d:
				CurrentPlayer.MoveRight ();
				break;
			}

			return base.OnKeyPressEvent (evnt);
		}

		public bool SetRedraw(){
			QueueDraw ();
			return true;
		}
	}
}

