<?hh // strict

/**
 * Markdown Parser
 * @author Nathan Davies, http://nathandavies.ninja
 * @copyright Copyright (c) 2016, Nathan Davies
 */

namespace Markdown\Parser;

use Markdown\Helper;

class Chunk
{
	private array<Line> $lines;
	private string $markup;

	/**
	 * Splits the chunks into its' parts/lines, and elevates their types
	 * @param string $chunk A chunk of markdown to be split into its' parts/lines
	 */
	public function __construct(string $chunk) : void
	{
		// Seperate the chunk by its' lines
		foreach(preg_split("/[\n]/", $chunk) as $line)
		{
			// Trim the line, is there still anything left?
			if (!strlen($line = trim($line)))
				continue;

			// Add line
			$this->lines []= new Line($line);
		}

		// Seperate types, and generate the mark-up
		$count = count($this->lines);
		for ($i = 0; $i < $count; $i)
		{
			$type = $this->lines[$i]->getType();

			// Standalone?
			if ($type::$isStandalone)
			{
				$this->markup .= call_user_func($type . "::markup", Helper::parse($type::$regex, $this->lines[$i]->markup()));
				$i++;
			}
			else
			{
				$contents = [];

				// Gather all parts belonging to this block
				$j = $i;
				while ($i < $count && $this->lines[$j]->compare($this->lines[$i])) {
					$contents []= Helper::parse($type::$regex, $this->lines[$i]->markup());
					$i++;
				}

				$this->markup .= call_user_func($type . "::markup", $contents);
			}
		}
	}

	/**
	 * Return the markup
	 * @return string The markup
	 */
	public function markup() : string
	{
		return $this->markup;
	}
}
