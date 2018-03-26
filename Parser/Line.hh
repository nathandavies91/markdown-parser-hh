<?hh // strict

/**
 * Markdown Parser
 * @author Nathan Davies, http://nathandavies.ninja
 * @copyright Copyright (c) 2016, Nathan Davies
 */

namespace Markdown\Parser;

use Markdown\Helper;

class Line
{
	private $type;
	private string $markup;

	/**
	 * Applies inline markup to the line of markdown
	 * @param string $chunk A line of markdown
	 */
	public function __construct(string $line) : void
	{
		$this->markup = $line;

		// Convert inline styling
		foreach ([$this->getType()] as $type)
		{
			if ($type::$includeInlines)
			{
				foreach (Helper::$inlineElements as $i)
					$this->markup = preg_replace_callback($i::$regex, $i."::markup", $this->markup);
			}
		}
	}

	/**
	 * Is the passed in line of the same type and status as the current line?
	 * @param Line $line The line to compare to
	 * @return bool
	 */
	public function compare(Line $line) : bool
	{
		return $this->getType() == $line->getType();
	}

	/**
	 * Interrogate the line to determine its' type
	 * @return string The type; for example "Paragraph"
	 */
	public function getType()
	{
		if ($this->type == null)
		{
			// Detect block type
			foreach (Helper::$blockElements as $i)
			{
				if (preg_match($i::$regex, $this->markup) > 0)
				{
					$this->type = $i;
					break;
				}
			}

			// Type undetermined, must be a paragraph
			if ($this->type == null)
				$this->type = Helper::getHelper("Paragraph");
		}

		return $this->type;
	}

	/**
	 * The lines markup
	 * @return string The markup
	 */
	public function markup() : string
	{
		return $this->markup;
	}
}
