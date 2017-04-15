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
	}
}

